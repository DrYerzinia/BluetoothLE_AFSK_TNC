
#ifndef AFSK_MODULATOR_H
#define AFSK_MODULATOR_H

#include <stdint.h>
#include <string.h>

#include "sin_table.h"

#define AFSK_MODULATOR_PACKET_FINISHED 0x100

#define MODULATOR_SAMPLE_RATE 11025
#define MAX_BYTES 255

typedef struct {

  uint8_t stage;

  uint8_t len;
  uint8_t data[MAX_BYTES];

  uint8_t start_preambles;
  uint8_t end_preambles;

  uint16_t bit_rate;

  uint16_t frequency_0;
  uint16_t frequency_1;

  uint16_t current_frequency;

  uint8_t same_count;
  uint16_t last_bit;
  uint32_t sample_counter;
  uint8_t phi;

} AFSK_Modulator;

#ifdef __cplusplus
extern "C" {
#endif

void AFSK_Modulator_init(uint8_t * data, uint8_t len, uint16_t bit_rate, uint16_t frequency_0, uint16_t frequency_1, uint8_t start_preambles, uint8_t end_preambles);

int16_t AFSK_Modulator_next_sample();

#ifdef __cplusplus
}
#endif

#endif
