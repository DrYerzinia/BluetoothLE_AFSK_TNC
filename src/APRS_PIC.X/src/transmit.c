#include "transmit.h"

static bool finished = false;

void __attribute__((interrupt, no_auto_psv)) _DAC1LInterrupt(void){

    IFS4bits.DAC1LIF = 0; // Clear Left Channel Interrupt Flag

    int16_t sample =  AFSK_Modulator_next_sample();

    if(sample == 0x0100){
        transmit_stop();
    } else {
        DAC1LDAT = sample << 8;
    }

}

void transmit_start(){
    LATBbits.LATB8 = 1;
    IFS4bits.DAC1LIF = 0;
    IEC4bits.DAC1LIE = 1;
    DAC1LDAT = 0;
    finished = false;
}

void transmit_stop(){
    IEC4bits.DAC1LIE = 0;
    finished = true;
    LATBbits.LATB8 = 0;
}

void transmit_setup(){

    // PPT output
    TRISBbits.TRISB8 = 0;
    LATBbits.LATB8 = 0;

    DAC1STATbits.LOEN = 1; // Enable left output
    DAC1STATbits.LITYPE = 0; // Interrupt on FIFO not full

    DAC1CONbits.AMPON = 0; /* Amplifier Disabled During Sleep and Idle Modes */
    // Tuned from experimentation
    DAC1CONbits.DACFDIV = 55; // 11025 sample rate
    DAC1CONbits.FORM = 0b01; // Signed Integer input

    DAC1DFLT = 0x0000; // Signed integer center value default

    IFS4bits.DAC1LIF = 0; // Clear Left Channel Interrupt Flag
    IEC4bits.DAC1LIE = 0; // Left Channel Interrupt Enabled

    DAC1CONbits.DACEN = 1;

}

void transmit_send(char *base64data){

    uint16_t len = strlen(base64data);
    base64data[len - 1] = '\0';
    len -= 2;
    base64data++;

    len = base64_decode(base64data);

    AFSK_Modulator_init((uint8_t*)base64data, len, 1200, 1200, 2200, 50, 10);

}

bool transmit_process(){
    return finished;
}