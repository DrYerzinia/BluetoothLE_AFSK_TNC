
#include "AFSK_Modulator.h"

#define PREAMBLE_START_STAGE 0
#define DATA_STAGE 1
#define PREAMBLE_END_STAGE 2
#define PACKET_SENT_STAGE 3


static AFSK_Modulator self;

void AFSK_Modulator_init(uint8_t * data, const uint8_t len, const uint16_t bit_rate, const uint16_t frequency_0, const uint16_t frequency_1, const uint8_t start_preambles, const uint8_t end_preambles){

  self.stage = 0;

  self.start_preambles = start_preambles;
  self.end_preambles = end_preambles;

  self.bit_rate = bit_rate;

  self.frequency_0 = frequency_0;
  self.frequency_1 = frequency_1;

  self.current_frequency = 0;

  self.len = len;
  memcpy(self.data, data, len);

  self.same_count = 0;
  self.last_bit = 0;
  self.sample_counter = 0;

  self.freq_0_phi_adjust = 256 * frequency_0 / MODULATOR_SAMPLE_RATE;
  self.freq_1_phi_adjust = 256 * frequency_1 / MODULATOR_SAMPLE_RATE;

}

static inline void AFSK_Modulator_advance_stage(){

  self.last_bit = 0;
  self.sample_counter = 0;
  self.stage++;

}

static inline void AFSK_Modulator_change_frequency(){

  if(self.current_frequency == 0)
    self.current_frequency = 1;

  else
    self.current_frequency = 0;

}

static int8_t AFSK_Modulator_next(const uint8_t freq){

  if(freq == 0)
    self.phi += self.freq_0_phi_adjust;
  else
    self.phi += self.freq_1_phi_adjust;
  self.sample_counter++;

  return sin_table[self.phi];

}

static int8_t AFSK_Modulator_get_preamble(const uint8_t num_preambles){

  uint16_t current_bit = self.sample_counter * self.bit_rate / MODULATOR_SAMPLE_RATE;

  if(current_bit != self.last_bit){

    if(current_bit % 8 <= 1)
      AFSK_Modulator_change_frequency();

    if(current_bit >= num_preambles * 8 + 1){
      AFSK_Modulator_change_frequency();
      AFSK_Modulator_advance_stage();
    }

    self.last_bit = current_bit;

  }

  return AFSK_Modulator_next(self.current_frequency);

}

static int8_t AFSK_Modulator_get_data(){

  uint16_t current_bit = self.sample_counter * self.bit_rate / MODULATOR_SAMPLE_RATE;

  if(current_bit != self.last_bit){

     // Bit stuffing
    if(self.same_count == 5){

      self.same_count = 0;
      self.sample_counter -= MODULATOR_SAMPLE_RATE / self.bit_rate;
      AFSK_Modulator_change_frequency();

    } else {

      // Change frequencies to indicate 0 bit
      if((self.data[current_bit / 8] & (1 << (current_bit % 8))) == 0)
        AFSK_Modulator_change_frequency();
 
      if(current_bit >= self.len * 8)
        AFSK_Modulator_advance_stage();

      self.last_bit = current_bit;

    }

    if((self.data[current_bit / 8] & (1 << (current_bit % 8))) != 0)
      self.same_count++;
    else
      self.same_count = 0;

  }

  return AFSK_Modulator_next(self.current_frequency);

}

int16_t AFSK_Modulator_next_sample(){

  switch(self.stage){
    case PREAMBLE_START_STAGE:
      return AFSK_Modulator_get_preamble(self.start_preambles);
    case DATA_STAGE:
      return AFSK_Modulator_get_data();
    case PREAMBLE_END_STAGE:
      return AFSK_Modulator_get_preamble(self.end_preambles);
    case PACKET_SENT_STAGE:
      return AFSK_MODULATOR_PACKET_FINISHED; // Indicates packet is finished
  }

  return 0x101; // ERROR: This should never happen
}
