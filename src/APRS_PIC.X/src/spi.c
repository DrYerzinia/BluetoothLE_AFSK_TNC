#include "spi.h"

uint8_t spi_transfer(uint8_t data){

    IFS0bits.SPI1IF = 0;
    SPI1STATbits.SPIRBF = 0;
    SPI1BUF = data;
    while(SPI1STATbits.SPIRBF == 0);
    return SPI1BUF;

}

void spi_cs(uint8_t state){

    if(!state){
        LATAbits.LATA3 = 0;
    } else {
        LATAbits.LATA3 = 1;
    }

}

void spi_master_init(){

    TRISAbits.TRISA3    = 0; // CS Output
    LATAbits.LATA3      = 1; // Start CS High

    TRISBbits.TRISB11   = 1; // SDI Input
    TRISBbits.TRISB5    = 0; // SCK Output
    TRISBbits.TRISB12   = 0; // SDO Output
    _SDI1R              = 11; // SDI  -> RP11
    RPOR2bits.RP5R     = SCK1RP; // RP5 -> SCK
    RPOR6bits.RP12R     = SDO1RP; // RP12 -> SDO

    IFS0bits.SPI1IF = 0; // Clear the Interrupt Flag
    IEC0bits.SPI1IE = 0; // Disable the Interrupt

    SPI1CON1bits.DISSCK = 0; // Internal Serial Clock Enabled
    SPI1CON1bits.DISSDO = 0; // SDO pin is controled by module
    SPI1CON1bits.MODE16 = 0; // 8-bit mode
    SPI1CON1bits.CKE    = 0; // Data Transistions on Idle to Active, Low->High, Leading
    SPI1CON1bits.CKP    = 0; // Clock Idle LOW, Active HIGH
    SPI1CON1bits.MSTEN  = 1; // Master

    SPI1STATbits.SPIROV = 0;

    SPI1STATbits.SPIEN = 1;	// Enable SPI Module

}

void spi_slave_init(){

    TRISAbits.TRISA3    = 0; // CS Output
    LATAbits.LATA3      = 1; // Start CS High

    TRISBbits.TRISB11   = 1; // SDI Input
    TRISBbits.TRISB5    = 1; // SCK Input
    TRISBbits.TRISB12   = 0; // SDO Output
    _SDI1R              = 6; //      SDI  -> RP6
    _SCK1R              = 5; // RP5  -> SCK
    RPOR6bits.RP12R     = SDO1RP; // RP12 ->SDO

    IFS0bits.SPI1IF = 0; // Clear the Interrupt Flag
    IEC0bits.SPI1IE = 0; // Disable the Interrupt

    SPI1CON1bits.DISSCK = 0; // Internal Serial Clock Disabled
    SPI1CON1bits.DISSDO = 0;// SDO pin is controled by module
    SPI1CON1bits.MODE16 = 0; // 8-bit mode
    SPI1CON1bits.CKE    = 0; // Data Transistions on Idle to Active, Low->High, Leading
    SPI1CON1bits.CKP    = 0; // Clock Idle LOW, Active HIGH
    SPI1CON1bits.MSTEN  = 0; // Slave

    SPI1STATbits.SPIROV = 0;

    SPI1STATbits.SPIEN = 1;	// Enable SPI Module

    IEC0bits.SPI1IE = 1; // Enable interrupt

}
