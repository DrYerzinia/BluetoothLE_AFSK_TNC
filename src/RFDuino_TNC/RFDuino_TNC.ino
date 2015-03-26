/* RFDuino_BLE_AFSK_TNC
 * Interfaces with a PIC controler to get Analog samples from the
 * audio output of a radio and demodulates the audio sending the
 * recivied packets over Bluetooth LE to connected devices
 * @author Michael Marques <dryerzinia@gmail.com>
 */

#include <RFduinoBLE.h>
#include <stdint.h>

#include "AFSK_Demodulator.h"
#include "AFSK_Modulator.h"
#include "crcccitt.h"

#define SCK   4
#define MOSI  5
#define MISO  3

#define BLE_START_PACKET      0x01
#define BLE_PACKET_CONTINUED  0x02
#define BLE_INPUT_VOLUME      0x03
#define BLE_BATTERY_VOLTAGE   0x04

uint8_t spi_wait_flag = 1;

#define RX_MODE 0
#define TX_MODE 1

#define RX_STAGE_1 0

#define TX_STAGE_1 1
#define TX_STAGE_2 2
#define TX_STAGE_3 3
#define TX_STAGE_4 4

uint8_t mode = RX_MODE;
uint8_t stage = RX_STAGE_1;

// Store up to 4 255 byte packets at once
#define NUM_PACKET_BUFFERS 4
#define PACKET_BUF_LEN 256

uint16_t start_packet_buffer = 0;
uint16_t end_packet_buffer = 0;
uint8_t packet_buffer[NUM_PACKET_BUFFERS][PACKET_BUF_LEN];

uint8_t send_packet_buffer_length = 0;
uint8_t send_packet_buffer_status = 0;
uint8_t send_packet_buffer[PACKET_BUF_LEN];

// Time
volatile uint64_t given_time = 0;
volatile uint64_t start_time = 0;

// Peak Volume Detection
#define SAMPLE_RATE 11025

uint16_t max_volume_sample_count = 0;
uint8_t max_volume = 0;

// Battery Voltage
#define BATTERY_MEASURE_PIN 2
#define BATTERY_UPDATE_SEC 10
uint8_t battery_update_count = 0;
uint8_t battery_measure_status = 2;

uint8_t battery_measurement;

// BLE Message Status
#define BLE_READY    0x00
#define BLE_BUFFERED 0x01

uint8_t ble_status = BLE_READY;

// Packet send via bluetooth
bool cnnected = false;
uint8_t packet_data[20];
uint8_t packet_data_len;
uint8_t packet_progress = 0;

void ADC_Setup(void) {

  NRF_ADC->CONFIG =
    (ADC_CONFIG_REFSEL_VBG << ADC_CONFIG_REFSEL_Pos) // Reference is 1.2V bandgap
    | (ADC_CONFIG_INPSEL_AnalogInputOneThirdPrescaling << ADC_CONFIG_INPSEL_Pos) // scale input to 1/3
    | ((1 << (BATTERY_MEASURE_PIN + 1)) << ADC_CONFIG_PSEL_Pos) // GPIO2 as Analog Input
    | (ADC_CONFIG_RES_8bit << ADC_CONFIG_RES_Pos) // 8 bit resolution
    | (ADC_CONFIG_EXTREFSEL_None << ADC_CONFIG_EXTREFSEL_Pos); // No External ADC Ref

  NRF_ADC->ENABLE = ADC_ENABLE_ENABLE_Enabled; // Enable ADC

}

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

  RFduinoBLE.deviceName = "BLE TNC";
  //RFduinoBLE.advertisementData = ""; // use for serial number
  RFduinoBLE.advertisementInterval = MILLISECONDS(1000);
  //RFduinoBLE.txPowerLevel = -20; // Find good middle ground -20dbM to +4 dbM

  RFduinoBLE.begin();

  AFSK_Demodulator_init(1200, 2200, 1200, d_from_float(0.0));

  SPI_Setup();
  ADC_Setup();
  pinMode(BATTERY_MEASURE_PIN, INPUT);
  pinMode(6, OUTPUT);

  //AFSK_Modulator_init(ARISS_data, ARISS_data_len, 1200, 1200, 2200, 120, 60);

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
  // 0x02 Send message from radio (Message Length + Data)
  // 0x03 Send message from radio (Message Data)
  // 0x04 Go to sleep
  // 0x05 Radio tuning if possible
  // 0x06 Adjust TX volume
  // 0x07 Set Time
  switch (data[0]) {
    case 0x01:
      break;
    case 0x02:
      // Set up sending message move
      // prepare to recieve packet data
      send_packet_buffer_length = data[1];
      send_packet_buffer_status = len - 2;
      for (uint8_t i = 0; i < len - 2; i++) {
        send_packet_buffer[i] = data[i + 2];
      }
      break;
    case 0x03:
      // Get data
      for (uint8_t i = 0; i < len - 1; i++) {
        send_packet_buffer[send_packet_buffer_status + i] = data[i + 1];
      }
      send_packet_buffer_status += len - 1;
      if (send_packet_buffer_status >= send_packet_buffer_length) {
        mode = TX_MODE; // Switch to TX Mode
        AFSK_Modulator_init(send_packet_buffer, send_packet_buffer_length, 1200, 1200, 2200, 120, 60); // Prepare Modulator
        stage = TX_STAGE_1; // Set tx stage 1
      }
      break;
    case 0x04:
      break;
    case 0x07:
      given_time = (data[0] << 48) + (data[1] << 32) + (data[2] << 16) + data[3];
      start_time = millis();
      break;
  }

}

// Persistent sample so we can run sample calculation during SPI transfer
//uint16_t sample;

void loop() {
/*
  // Code for testing sample caluculation time
  NRF_GPIO->OUTSET = (1 << 6);
  uint16_t sample = AFSK_Modulator_next_sample();
  NRF_GPIO->OUTCLR = (1 << 6);

  if(sample == 0x100)
    AFSK_Modulator_init(ARISS_data, ARISS_data_len, 1200, 1200, 2200, 120, 60);

  return;
*/
  // Start SPI request for ADC Sample
  if (spi_wait_flag) {

    // SPI Output Codes
    // RX Mode
    // 0X7E Get ADC Sample
    // 0x7F Switch to TX Mode
    // TX Mode
    // 0x7F Final sample switch back to RX Mode

    if (mode == RX_MODE) {

      NRF_SPI0->TXD = 'B'; // get next ADC sample

    } else if (mode == TX_MODE) {

      // if starting send 0x7E to switch to DAC mode
      if (stage == TX_STAGE_1) {

        NRF_SPI0->TXD = 0x7E;
        stage = TX_STAGE_2;
        // While TXing byte to switch to DAC mode
        // Start calculating first sample
        //sample = AFSK_Modulator_next_sample();

      }
      // else send next tx byte from modulator
      else if (stage == TX_STAGE_2) {

        int16_t sample = AFSK_Modulator_next_sample();

        // process previously calculated sample
        // if modulator 0x100 recived finished sending wait for tx buffer to empty
        if (sample == AFSK_MODULATOR_PACKET_FINISHED) {
          NRF_SPI0->TXD = 0x7E; // NULL data character
          stage = TX_STAGE_3;

        } else {

          // Don't send 0x7F or 0x7E those are special codes
          if (sample == 0x7F || sample == 0x7E)
            NRF_SPI0->TXD = 0x7D;
          else
            NRF_SPI0->TXD = (uint8_t)(sample & 0xFF);

          // start calculating next sample during SPI Xfer
          //sample = AFSK_Modulator_next_sample();

        }
      }
      else if (stage == TX_STAGE_3) {

        NRF_SPI0->TXD = 0x7E; // Send 7E because we have no further data for buffer

      } else if (stage == TX_STAGE_4) {

        mode = RX_MODE;
        stage = RX_STAGE_1;
        NRF_SPI0->TXD = 0x7F; // Switch back to ADC mode

      }

    }

    spi_wait_flag = 0;

  }

  if (NRF_SPI0->EVENTS_READY != 0) {

    spi_wait_flag = 1;
    NRF_SPI0->EVENTS_READY = 0;
    uint8_t data = NRF_SPI0->RXD;

    // Special codes
    // RX Mode
    // 0x7F Buffer Empty or Radio Squelched sleep 1 ms
    // TX Mode
    // 0x7F Buffer Full sleep 1 ms
    // 0x7E TX Finished

    if (mode == RX_MODE) {

      if (data == 0x7F) {

        // Ignore sample buffer is empty or radio is squelched
        // Sleep for 1ms while buffer refills
        RFduino_ULPDelay(1);

      } else {

        // Get maximum volume
        max_volume_sample_count++;
        if (data < 0x7F && data > max_volume) {
          max_volume = data;
        }

        // Got ADC sample, proccess it
        AFSK_Demodulator_proccess_byte((int8_t)data, packet_buffer[end_packet_buffer]);
        if (packet_buffer[end_packet_buffer][0] != 0) {

          uint16_t fsc = CRCCCITT(packet_buffer[end_packet_buffer] + 1, packet_buffer[end_packet_buffer][0] - 2, 0x8408);

          // CRC is added to packet with bytes reversed
          uint16_t fsc2 = packet_buffer[end_packet_buffer][packet_buffer[end_packet_buffer][0]];
          fsc2 <<= 8;
          fsc2 |= packet_buffer[end_packet_buffer][packet_buffer[end_packet_buffer][0] - 1] & 0xFF;

          if (fsc == fsc2) {

            end_packet_buffer++;
            if (end_packet_buffer == NUM_PACKET_BUFFERS)
              end_packet_buffer = 0;

          } else {

            // CRC failed mark in packet buffer as empty
            packet_buffer[end_packet_buffer][0] = 0;

          }

        }
      }

    } else if (mode == TX_MODE) {

      // Buffer ok keep sending
      if (data == 0x7E) {

      } else if (data == 0x7F) {
        // Buffer full delay atleast 1 sample time before sending more data
        RFduino_ULPDelay(1);
      } else if (data == 0x7D && stage == TX_STAGE_3) {
        // Buffer empty and stage 3 switch to stage 4
        stage = TX_STAGE_4;
      }

    }
  }
  // Handle sending any decoded packets via BLE
  if (cnnected) {

    if (ble_status == BLE_BUFFERED) {
      boolean stat = RFduinoBLE.send((const char *)(packet_data), packet_data_len);
      if (stat == 1)
        ble_status = BLE_READY;
    }

    if (battery_measure_status == 0) {

      if ((NRF_ADC->BUSY & ADC_BUSY_BUSY_Msk) != (ADC_BUSY_BUSY_Busy << ADC_BUSY_BUSY_Pos)) {

        battery_measure_status = 1;
        battery_measurement = NRF_ADC->RESULT & 0xFF;

      }

    }

    if (ble_status == BLE_READY) {

      // Send battery status 1/10 Hz
      if (battery_measure_status == 1) {

        packet_data[0] = BLE_BATTERY_VOLTAGE;
        packet_data[1] = battery_measurement;

        packet_data_len = 2;

        ble_status = BLE_BUFFERED;

        battery_measure_status = 2;

      }
      // Send input volume 1 Hz
      else if (max_volume_sample_count >= SAMPLE_RATE) {

        packet_data[0] = BLE_INPUT_VOLUME;
        packet_data[1] = max_volume;

        packet_data_len = 2;

        max_volume = 0;
        max_volume_sample_count = 0;

        ble_status = BLE_BUFFERED;

        battery_update_count++;
        if (battery_update_count >= BATTERY_UPDATE_SEC) {
          battery_update_count = 0;
          battery_measure_status = 0;
          NRF_ADC->TASKS_START = 1; // Start Battery Measurment Conversion
        }

      } else if (packet_buffer[start_packet_buffer][0] != 0) {

        uint8_t fill_start;

        if (!packet_progress) {

          // 0x01 Start Send packet
          // 2nd byte length
          // remaining 18 bytes data
          // Send the packet length
          packet_data[0] = BLE_START_PACKET;
          packet_data[1] = packet_buffer[start_packet_buffer][0];

          fill_start = 2;

        } else {

          // 0x02 packet data continuted
          packet_data[0] = BLE_PACKET_CONTINUED;

          fill_start = 1;

        }

        uint8_t len = packet_buffer[start_packet_buffer][0] - packet_progress;
        if (len > 20 - fill_start)
          len = 20 - fill_start;

        uint8_t i;
        for (i = 0; i < len; i++) {
          packet_data[i + fill_start] = packet_buffer[start_packet_buffer][packet_progress + i + 1];
        }

        ble_status = BLE_BUFFERED;
        packet_data_len = len + fill_start;

        packet_progress += len;

        if (packet_progress >= packet_buffer[start_packet_buffer][0]) {

          packet_progress = 0;
          packet_buffer[start_packet_buffer][0] = 0;

          start_packet_buffer++;

          if (start_packet_buffer == NUM_PACKET_BUFFERS)
            start_packet_buffer = 0;


        }

      }
    }
  }
}

