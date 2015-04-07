#include "main.h"

#define COMMAND_BUFFER_SIZE 400

static char command_buffer[COMMAND_BUFFER_SIZE];
static uint8_t command_buffer_position = 0;

const char STATUS_OK[] = "OK";

#define RX_MODE 0
#define TX_MODE 1

uint8_t mode = RX_MODE;

void inline print_ok(){
    printf("%s\n\r", STATUS_OK);
}

void console_input(char c){

    switch(c){
        case 0x0A:	// New Line
        case 0x0D:	// Carriage Return

            //printf("\n\r");
            command_buffer[command_buffer_position] = '\0';

            if(strcmp(command_buffer, "hello") == 0){

                printf("HI\n\r");

            } else if(strcmp(command_buffer, "rcon") == 0){

                printf("%04x\n\r", RCON);

            } else if(strcmp(command_buffer, "clr_rcon") == 0){

                RCON = 0;
                print_ok();

            } else if(strncmp(command_buffer, "TX=", 3) == 0){

                mode = TX_MODE;
                receive_stop();
                transmit_send(command_buffer + 3);
                transmit_start();

            } else {

                printf("str\n\r");

            }

            command_buffer_position = 0;

            break;

        /* // TNC MAKES NO MISTAKE!
        case 0x7F:	// Delete
        case 0x08:	// Backspace

            if(command_buffer_position > 0){
                command_buffer_position--;
                putch(c);
            }
            */

            break;

        default:

            command_buffer[command_buffer_position] = c;
            command_buffer_position++;

            if(command_buffer_position == COMMAND_BUFFER_SIZE)
                command_buffer_position--;
            // ECHO off for TNC
            //else
                //putch(c);

            break;

    }

}

int main(void){

    // Configure PLL prescaler, PLL postsscaer, PLL divisor
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0;	// n2 = 2
    CLKDIVbits.PLLPRE  = 0;	// n1 = 2

    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);

    // Wait for Clock switch to occur
    while(OSCCONbits.COSC != 0b001);

    // Wait for PLL to lock
    while(OSCCONbits.LOCK != 1);

    ACLKCONbits.APSTSCLR = 0b111; // Divide aux clock by 1

    INTCON1bits.NSTDIS = 1; // Disable interrupt nesting

    receive_setup();
    transmit_setup();

    console_init(console_input);

    IEC4bits.DAC1LIE = 0;

    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = 0;

    receive_start();

    AFSK_Demodulator_init(1200, 2200, 1200, d_from_float(0.0));

    __delay_ms(500);// delay for BLE INIT TIME
    printf("str\n\r"); // start stream mode BlE TNC

    //printf("BluetoothLE TNC Active\n\r");

    while(1){
        if(mode == RX_MODE){
            receive_process();
        } else if(mode == TX_MODE){
            if(transmit_process()){
                print_ok();
                receive_start();
                mode = RX_MODE;
            }
        }
    }

    return 0;

}