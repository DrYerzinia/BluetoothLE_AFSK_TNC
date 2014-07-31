/* RFDuino_BLE_AFSK_TNC
 * Interfaces with a PIC controler to get Analog samples from the
 * audio output of a radio and demodulates the audio sending the
 * recivied packets over Bluetooth LE to connected devices
 * @author Michael Marques <dryerzinia@gmail.com>
 */

#include <RFduinoBLE.h>
#include <stdint.h>

#include "AFSK_Demodulator.h"
#include "crcccitt.h"

#define SCK   4
#define MOSI  5
#define MISO  3

// Store up to 4 255 byte packets at once
#define NUM_PACKET_BUFFERS 4
#define PACKET_BUF_LEN 256

uint8_t start_packet_buffer = 0;
uint8_t end_packet_buffer = 0;
uint8_t packet_buffer[NUM_PACKET_BUFFERS][PACKET_BUF_LEN];

// Packet send via bluetooth
bool sent_len = false;
bool cnnected = false;
uint8_t packet_progress = 0;

void SPI_Setup(void) {

  // Disable peripheral's with same ID as SPI and SPI
  NRF_SPI0->ENABLE = 0;

  // All SPIS pins should be configured as inputs
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);

  NRF_SPI0->PSELMOSI = MOSI;
  NRF_SPI0->PSELMISO = MISO;
  NRF_SPI0->PSELSCK  = SCK;

  NRF_SPI0->FREQUENCY = (SPI_FREQUENCY_FREQUENCY_M2 << SPI_FREQUENCY_FREQUENCY_Pos);

  NRF_SPI0->CONFIG =
    (
      (SPI_CONFIG_CPOL_ActiveHigh << SPIS_CONFIG_CPOL_Pos) |
      (SPI_CONFIG_CPHA_Trailing << SPIS_CONFIG_CPHA_Pos) |
      (SPI_CONFIG_ORDER_MsbFirst << SPIS_CONFIG_ORDER_Pos)
    );

  NRF_SPI0->EVENTS_READY = 0;

  NRF_SPI0->ENABLE = SPI_ENABLE_ENABLE_Enabled;

}

void setup() {

  Serial.begin(9600);

  RFduinoBLE.begin();
  AFSK_Demodulator_init(1200, 2200, 1200);
  SPI_Setup();

}

void RFduinoBLE_onConnect() {

  cnnected = true;

}

void RFduinoBLE_onDisconnect() {

  cnnected = false;

}

void RFduinoBLE_onReceive(char *data, int len) {

  // Messages types:
  // 0x01 Change Decoder Parameters
  // 0x02 Send message from radio
  // 0x03 Go to sleep
  // 0x04 Radio tuning if possible
  switch(data[0]){
    case 0x01:
      break;
    case 0x02:
      // Set up sending message move
      // prepare to recieve packet data
      break;
    case 0x03:
      break;
    case 0x04:
      break;
  }

}

uint8_t spi_wait_flag = 1;

void loop() {

  // Start SPI request for ADC Sample
  if(spi_wait_flag){

    // SPI Output Codes
    // RX Mode
    // 0X41 Get ADC Sample
    // 0x42 Switch to TX Mode
    // TX Mode
    // 0x7F Final sample switch back to RX Mode

    NRF_SPI0->TXD = 'A'; // A for get next ADC sample

    spi_wait_flag = 0;
  }

  if(NRF_SPI0->EVENTS_READY != 0){

    spi_wait_flag = 1;
    NRF_SPI0->EVENTS_READY = 0;
    uint8_t data = NRF_SPI0->RXD;

    // Special codes
    // RX Mode
    // 0x7F Buffer Empty or Radio Squelched sleep 1 ms
    // TX Mode
    // 0x7F Buffer Full sleep 1 ms
    // 0x7E TX Finished

    if(data == 0x7F){

      // Ignore sample buffer is empty or radio is squelched
      // Sleep for 1ms while buffer refills
      RFduino_ULPDelay(1);

    } else {

      // Got ADC sample, proccess it
      AFSK_Demodulator_proccess_byte((int8_t)data, packet_buffer[end_packet_buffer]);
      if (packet_buffer[end_packet_buffer][0] != 0) {
  
        uint16_t fsc = CRCCCITT(packet_buffer[end_packet_buffer] + 1, packet_buffer[end_packet_buffer][0] - 2, 0x8408);
  
        // CRC is added to packet with bytes reversed
        uint16_t fsc2 = packet_buffer[end_packet_buffer][packet_buffer[end_packet_buffer][0]];
        fsc2 <<= 8;
        fsc2 |= packet_buffer[end_packet_buffer][packet_buffer[end_packet_buffer][0]-1] & 0xFF;
  
        if(fsc == fsc2){
  
          end_packet_buffer++;
          if (end_packet_buffer == NUM_PACKET_BUFFERS)
            end_packet_buffer = 0;
  
        } else {
  
          // CRC failed mark in packet buffer as empty
          packet_buffer[end_packet_buffer][0] = 0;
  
        }

      }
    }

  }

  // Handle sending any decoded packets via BLE
  if (cnnected) {

    if (packet_buffer[start_packet_buffer][0] != 0) {

      if (sent_len) {

        uint8_t len = packet_buffer[start_packet_buffer][0] - packet_progress + 0;
        if (len > 20)
          len = 20;

        if (RFduinoBLE.send((const char *)(packet_buffer[start_packet_buffer] + packet_progress + 1), len)) {

          packet_progress += len;

          if (packet_progress >= packet_buffer[start_packet_buffer][0]) {

            packet_progress = 0;
            packet_buffer[start_packet_buffer][0] = 0;

            start_packet_buffer++;

            if (start_packet_buffer == NUM_PACKET_BUFFERS)
              start_packet_buffer = 0;

            sent_len = false;

          }

        }

      } else {

        // Send the packet length
        RFduinoBLE.send(packet_buffer[start_packet_buffer][0]);
        sent_len = true;

      }

    }

  } 

}

