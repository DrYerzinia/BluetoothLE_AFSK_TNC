/* 
 * File:   main.c
 * Author: mike
 *
 * Created on July 31, 2014, 10:44 PM
 */

#include <xc.h>

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCDDIS = ON      // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = ON       // Low-Power Brown Out Reset (Low-Power BOR is enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <pic16lf1704.h>

// DAC Mode
#define BUFFER_OK    0x7E
#define BUFFER_FULL  0x7F
#define BUFFER_EMPTY_DAC_MODE 0x7D
#define NULL_DATA 0x7E

// ADC Mode
#define BUFFER_EMPTY 0x7F
#define BUFFER_EMPTY_M_1 0x7E

#define SWITCH_ADC_MODE 0x7F
#define SWITCH_DAC_MODE 0x7E

#define ADC_MODE 0
#define DAC_MODE 1

uint8_t mode = ADC_MODE;

bool dac_started = false;

bool overflow = false;

uint8_t data_buffer[256];
uint8_t data_buffer_write_pos = 0;
uint8_t data_buffer_read_pos = 0;

void interrupt isr(void){

    if(PIR1bits.SSP1IF){

        uint8_t data = SSP1BUF;

        if(mode == ADC_MODE){

            if(data == SWITCH_DAC_MODE){

                mode = DAC_MODE;

                // Stop ADC
                // Start DAC

                // Reset buffer
                data_buffer_write_pos = 0;
                data_buffer_read_pos = 0;

                dac_started = false;

            } else {

                if(data_buffer_write_pos != data_buffer_read_pos)
                    SSP1BUF = data_buffer[data_buffer_read_pos++];
                else
                    SSP1BUF = BUFFER_EMPTY;

            }

        } else if(mode == DAC_MODE){

            if(data == SWITCH_ADC_MODE){

                mode = ADC_MODE;

                // Stop DAC
                DAC1CON1bits.DAC1R = 0x80;
                // Start ADC

                // Stop PTT
                LATAbits.LATA2 = 0;

                // Reset buffer
                data_buffer_write_pos = 0;
                data_buffer_read_pos = 0;

            } else if(data != NULL_DATA){

                if(data < 0x80) data += 0x80;
                else data -= 0x80;

                // Buffer data
                data_buffer[data_buffer_write_pos++] = data;

                if(!dac_started && data_buffer_write_pos > 200){

                    dac_started = true;

                    // Trigger PTT
                    LATAbits.LATA2 = 1;

                }

                if(data_buffer_write_pos + 3 != data_buffer_read_pos)
                    SSP1BUF = BUFFER_OK;
                else
                    SSP1BUF = BUFFER_FULL;

                overflow = false;

            } else {

                if(overflow){
                    SSP1BUF = BUFFER_EMPTY_DAC_MODE;
                }

            }

        }

        PIR1bits.SSP1IF = 0;

    }
    else if(PIR1bits.ADIF){

        uint8_t adc_result = ADRESH;

        // convert result to signed number
        if(adc_result >= 0x80)
            adc_result -= 0x80;
        else
            adc_result += 0x80;

        if(adc_result == BUFFER_EMPTY)
            data_buffer[data_buffer_write_pos++] = BUFFER_EMPTY_M_1;
        else
            data_buffer[data_buffer_write_pos++] = adc_result;

        PIR1bits.ADIF = 0;

    }
    else if(INTCONbits.TMR0IF){

        if(mode == ADC_MODE){

            TMR0 = TMR0 + 0x4E; // 11025 Hz

            // Take ADC Sample
            ADCON0bits.GO = 1;

        } else if(mode == DAC_MODE) {

            TMR0 = TMR0 + 0x4E;//0xA7; // 22050 Hz

            // TODO check for buffer overrun and shutdown if it happens
            // Next output
            if(!dac_started);
            else if(data_buffer_read_pos == data_buffer_write_pos){

                overflow = true;

                mode = ADC_MODE;

                // Stop DAC
                DAC1CON1bits.DAC1R = 0x80;
                // Start ADC

                // Stop PTT
                LATAbits.LATA2 = 0;

                // Reset buffer
                data_buffer_write_pos = 0;
                data_buffer_read_pos = 0;

            } else {

                DAC1CON1bits.DAC1R = data_buffer[data_buffer_read_pos++];

            }

        }

        INTCONbits.TMR0IF = 0;

    }

}

void main(void) {

    // Switch clock to 16 MHz
    OSCCONbits.IRCF = 0b1111;
    OSCCONbits.SCS = 0b10;

    while(OSCSTATbits.HFIOFS == 0); // Wait for clock to stabalize

    SLRCONAbits.SLRA2 = 0;
    TRISAbits.TRISA2 = 0;
    LATAbits.LATA2 = 0;

    // Setup PPI
    // Unlock PPS
    GIE = 0; // Disable Interrupts, TODO remove this is init code its unnessisary
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 0x00;

    // SPI PPI
    RA5PPSbits.RA5PPS       = 0b10010; // SDO
    SSPCLKPPSbits.SSPCLKPPS = 0b10000; // RC0
    SSPDATPPSbits.SSPDATPPS = 0b10001; // RC1

    // Lock PPS
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 0x01;

    // Op-Amp Config
    OPA2CONbits.OPA2SP = 0; // Low GBWP set
    OPA2CONbits.OPA2UG = 0; // Unity gain off - to output
    OPA2CONbits.OPA2PCH = 0b00; // Attached + to pin

    OPA2CONbits.OPA2EN = 1;

    OPA1CONbits.OPA1SP = 0; // Low GBWP set
    OPA1CONbits.OPA1UG = 1; // Unity gain on
    OPA1CONbits.OPA1PCH = 0b10; // Attached + to DAC Output

    OPA1CONbits.OPA1EN = 1;

    // ADC Config
    TRISAbits.TRISA4 = 1; // Analog input on RA4

    // Disable interrupt and clear flag
    PIE1bits.ADIE = 0;
    PIR1bits.ADIF = 0;

    ANSELA = 0; // Disable all ANIN
    ANSELC = 0;
    ANSELAbits.ANSA4 = 1; // Enable RA4 as analog input

    ADCON0bits.CHS = 0b00011; // AN3

    ADCON1bits.ADFM = 0; // Align conversion left to get 8 high bits easily
    ADCON1bits.ADCS = 0b111; // Clock Source is FRC 1-6 uS conversion Time
    ADCON1bits.ADPREF = 0b00; // Vcc is AD references

    ADCON2bits.TRIGSEL = 0x0000; // Auto conversion disabled

    ADCON0bits.ADON = 1; // Enable ADC

    PIE1bits.ADIE = 1; // Enabled ADC interrupt

    // DAC Config
    DAC1CON0bits.DAC1PSS = 0; // + ref VDD
    DAC1CON0bits.DAC1NSS = 0; // - ref VSS

    DAC1CON1bits.DAC1R = 0x80; // Default output Voltage VSS

    DAC1CON0bits.DAC1EN = 1;

    // PTT Config
    TRISAbits.TRISA2 = 0;
    LATAbits.LATA2 = 0; // PPT low by default

    // Timer0 Config

    // Disable interupt and clear flag
    INTCONbits.TMR0IE = 0;
    INTCONbits.TMR0IF = 0;

    OPTION_REGbits.T0CS = 0; // Timer0 Fosc/4 clock
    OPTION_REGbits.PSA = 0; // Prescaler assigned to timer 0
    OPTION_REGbits.PS = 0b000; // Prescaller 1:2

    INTCONbits.TMR0IE = 1; // Enable Timer 0 Interrupts

    // SPI Config
    // Configure IO Directions
    TRISAbits.TRISA5 = 0;
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;

    // Clear and disable SPI interrupts
    PIR1bits.SSP1IF = 0;
    PIE1bits.SSP1IE = 0;

    SSP1STATbits.CKE = 0; // Data Transistions on Idle to Active, Low->High, Leading
    SSP1STATbits.SMP = 0; // Data sampling in middle of data output time

    SSP1CON1bits.CKP = 0; // Clock Idle LOW, Active HIGH
    SSP1CON1bits.SSPM = 0b0101; // SPI Slave mode SS disabled

    SSP1CON3bits.BOEN = 1; // Ignore Buffer Overflows

    while(PORTCbits.RC0 == 1); // Wait for clock to become idle

    SSP1CON1bits.SSPEN = 1; // Enable SPI

    PIE1bits.SSP1IE = 1; // Enable SPI Interrupts

    // Enable all interrupts
    INTCONbits.PEIE = 1; // Enable Peripheral Interrupts
    INTCONbits.GIE = 1; // Enable Interrupts

    // Load SPI buffer so its ready for first pull
    SSP1BUF = 'A';

    while(1){} // Run forever

}
