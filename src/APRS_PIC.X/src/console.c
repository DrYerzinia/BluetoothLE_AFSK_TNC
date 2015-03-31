#include "console.h"

// Need to be long enough for a 255 byte long Base64 encoded data packet
#define CONSOLE_BUFFER_SIZE 400

static uint16_t console_buf_rpos = 0;
static uint16_t console_buf_wpos = 0;
static uint16_t console_buf[CONSOLE_BUFFER_SIZE];

static void (*rx_callback)(char) = NULL;

int putch(int c){

    // if(console_buf_wpos == console_buf_rpos) buffer overrun error

    console_buf[console_buf_wpos++] = c;

    if(console_buf_wpos >= CONSOLE_BUFFER_SIZE)
        console_buf_wpos = 0;

    // If we are not TXing start UART TX interupt cycle
    if(U1STAbits.TRMT == 1){

        IEC0bits.U1TXIE = 0;

        if(U1STAbits.UTXBF == 0){
            U1TXREG = console_buf[console_buf_rpos++];
            if(console_buf_rpos >= CONSOLE_BUFFER_SIZE)
                console_buf_rpos = 0;
        }

        IEC0bits.U1TXIE = 1;

    }

    return 1;

}

void console_init(void *rxcb){

    rx_callback = rxcb;

    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB10 = 1;
    RPOR5bits.RP11R = U1TXRP; // RP11 TX
    RPINR18bits.U1RXR = 10;  // RP10 RX

    U1MODEbits.STSEL    = 0; // 1-stop bit
    U1MODEbits.PDSEL    = 0; // No parity
    U1MODEbits.ABAUD    = 0; // Autobaud disabled
    U1MODEbits.BRGH     = 1; // High Speed mode

    U1MODEbits.USIDL    = 0; // Run IDLE
    U1MODEbits.WAKE     = 1; // Wake from sleep

    U1BRG = U1BRGVAL;        // Set baude rate

    U1STAbits.URXISEL   = 0; // Interrupt after 1 RX char received

    IEC0bits.U1RXIE     = 1; // Enable U1RX Interrupt

    U1MODEbits.UARTEN   = 1;
    U1STAbits.UTXEN     = 1; // Enable UART TX

}

void __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt(void){

    IFS0bits.U1RXIF = 0;

    if(U1STAbits.OERR == 1) U1STAbits.OERR = 0; // Ignore errors

    if(U1STAbits.URXDA == 1 && rx_callback != NULL)
        rx_callback(U1RXREG);

}

void __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt(void){

    IFS0bits.U1TXIF = 0;

    if(console_buf_wpos != console_buf_rpos){

        U1TXREG = console_buf[console_buf_rpos++];

        if(console_buf_rpos >= CONSOLE_BUFFER_SIZE)
            console_buf_rpos = 0;

    }

}