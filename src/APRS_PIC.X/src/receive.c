#include "receive.h"

#define ADC_BUFFER_SIZE 4

static int8_t adc_buffer[ADC_BUFFER_SIZE];
static uint8_t adc_buffer_rpos = 0;
static uint8_t adc_buffer_wpos = 0;

static uint8_t data_buffer[MAX_APRS_PACKET_SIZE];

static uint8_t mode = RECEIVE_PRINT_MODE_BASE64;

static APRSPacket last_rxed;

void print_packet(APRSPacket * packet){

    if(!APRSPacket_crc_is_valid(packet)) return;

    if(mode == RECEIVE_PRINT_MODE_BASE64){

        char base64_packet[400];
        base64_encode(data_buffer + 1, base64_packet, data_buffer[0]);
        printf("RX=\"%s\"\n\r", base64_packet);

    } else {

        APRSPacket_print_detailed(packet);

    }

}

void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void){

    IFS0bits.AD1IF = 0;

    int16_t adc_value = ADC1BUF0;

    // Offload hardwork to main loop
    adc_buffer[adc_buffer_wpos++] = (int8_t)((adc_value >> 2) & 0xFF);
    if(adc_buffer_wpos >= ADC_BUFFER_SIZE)
        adc_buffer_wpos = 0;

}

void receive_start(){
    T3CONbits.TON = 1;
}

void receive_stop(){
    T3CONbits.TON = 0;
}

void receive_setup(){

    T3CONbits.TCS = 0; // Internal Clock
    T3CONbits.TGATE = 0; // Gate time accumulation disabled
    T3CONbits.TCKPS = 0b00; // 1:1 prescaler

    // Fcy = 39613750
    // Fcy / 11025 = 3593.08

    PR3 = 3593; // 11025sps
    // Measured 11042
    // 0.15% error

    AD1PCFGL = 0b1111111111011111; // Input AN5 enabled

    AD1CON1bits.SSRC = 0b010; // Trigger on Timer 3 event
    AD1CON1bits.FORM = 0b01; // signed integer
    AD1CON1bits.ASAM = 1; // Automaticly start sampling right after convrsion

    AD1CON2bits.VCFG = 0b000; // Reference Avdd Avss

    AD1CHS0bits.CH0SA = 5; // AN5 input select

    IFS0bits.AD1IF = 0; // Clear ADC interrupt flag
    IEC0bits.AD1IE = 1; // Enable ADC interrupts

    AD1CON1bits.ADON = 1;

}

void receive_process(){

    if(adc_buffer_rpos != adc_buffer_wpos){

        AFSK_Demodulator_proccess_byte(adc_buffer[adc_buffer_rpos++], data_buffer);
        if(adc_buffer_rpos >= ADC_BUFFER_SIZE)
            adc_buffer_rpos = 0;

        if(data_buffer[0] != 0){

            APRSPacket_from_data(&last_rxed, data_buffer + 1, (uint8_t)(data_buffer[0]));
            print_packet(&last_rxed);
            data_buffer[0] = 0;

        }
    }
}
