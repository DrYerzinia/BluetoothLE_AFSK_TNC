// AFSK_Demodulator.c

#include "AFSK_Demodulator.h"

static AFSK_Demodulator self;

void AFSK_Demodulator_reset() {

  self.count_last = 0;

  /*
   * Calculate Goertzel coefficents for calculating frequency magnitudes
   */
  float k0 = ((float)WINDOW * FREQUENCY0 / SAMPLE_RATE);
  float k1 = ((float)WINDOW * FREQUENCY1 / SAMPLE_RATE);
  float w0 = (2 * PI / WINDOW) * k0;
  float w1 = (2 * PI / WINDOW) * k1;

  self.coeff0 = d_from_float(2 * cos(w0));
  self.coeff1 = d_from_float(2 * cos(w1));

  self.last_bit = 0;

  self.bit_stuffing = false;

  if (self.input_buffer.size != 0)
    decimal_ring_buffer_destory(&self.input_buffer);
  decimal_ring_buffer_init(&self.input_buffer, WINDOW + 2);

  self.fcd_filt = 0;

  self.byte_seq_len = 0;

  char_ring_buffer_clear(&self.bit_sequence);

}

void AFSK_Demodulator_init() {

  self.input_buffer.size = 0;

  self.fcd_filt = 0;
  self.byte_seq_len = 0;

  char_ring_buffer_init(&self.bit_sequence, 14);

  AFSK_Demodulator_reset(self);

}

void AFSK_Demodulator_proccess_byte(int8_t data_point, uint8_t * new_data) {

  new_data[0] = 0;

  decimal_ring_buffer_put(&self.input_buffer, d_from_int(data_point));

  if (decimal_ring_buffer_avail(&self.input_buffer) > WINDOW) {

    decimal q1_0 = 0;
    decimal q1_1 = 0;
    decimal q2_0 = 0;
    decimal q2_1 = 0;

    int16_t i;
    for (i = 0; i <= WINDOW; i++) {

      decimal q0_0 = dcmul(self.coeff0, q1_0) - q2_0 + decimal_ring_buffer_get(&self.input_buffer, i);
      decimal q0_1 = dcmul(self.coeff1, q1_1) - q2_1 + decimal_ring_buffer_get(&self.input_buffer, i);
      q2_0 = q1_0;
      q2_1 = q1_1;
      q1_0 = q0_0;
      q1_1 = q0_1;

    }

    decimal fc1 = dcmul(q1_0, q1_0) + dcmul(q2_0, q2_0) - dcmul(dcmul(q1_0, q2_0), self.coeff0);
    decimal fc2 = dcmul(q1_1, q1_1) + dcmul(q2_1, q2_1) - dcmul(dcmul(q1_1, q2_1), self.coeff1);

    /* The 1800 Offset needs to be calculated based on the amplitude of the incomming signal
     * the radio should have a tunning utility so it will turn on an LED when the signal amplitude
     * is in the ideal range for the offset
     */
    decimal fcd = fc1 - fc2 - d_from_float(1800.0);

    decimal_ring_buffer_pop(&self.input_buffer);

    // Moving average filter
    self.fcd_filt = self.fcd_filt + dmul((fcd - self.fcd_filt), d_from_float(0.4)); // FILT <-- FILT + FF(NEW - FILT)

    uint8_t current_value = 0;
    if (self.fcd_filt < 0)
      current_value = 1;

    if (current_value != self.last_bit) {

      self.last_bit = current_value;

      // Calculate how many bit lengths there are to the transition
      // Integer rounding
      uint8_t bitwidth = BIT_WIDTH;
      uint8_t new_bits = (self.count_last + (bitwidth / 2)) / bitwidth;

      // If we are not bit stuffing Add a 0
      if (!self.bit_stuffing)
        char_ring_buffer_put(&self.bit_sequence, 0);

      // If we where bit stuffing stop now
      self.bit_stuffing = false;

      // Decrement new_bits
      new_bits--;

      // If new_bits > 5 we just found a preamble
      if (new_bits > 5) {

        // Preamble related things

        uint16_t len = self.byte_seq_len;
        if (len >= 17) {

          new_data[0] = len;
          memcpy(new_data + 1, &self.byte_sequence, len);

        }

        self.byte_seq_len = 0;
        char_ring_buffer_clear(&self.bit_sequence);

        // Set bit stuffing true so last bit of preamble will be removed
        self.bit_stuffing = true;

      }

      // If its not a preamble
      else {

        // If new_bits == 5 bit stuffing is occurring
        if (new_bits == 5)
          self.bit_stuffing = true;

        // Add the rest of the bits as 1's
        for (i = 0; i < new_bits; i++)
          char_ring_buffer_put(&self.bit_sequence, 1);

      }

      // Add bits to the sequence
      uint8_t avail = char_ring_buffer_avail(&self.bit_sequence);
      if (avail >= 8) {

        int8_t dat = 0;
        for (i = 7; i >= 0; i--) {
          dat <<= 1;
          if (char_ring_buffer_get(&self.bit_sequence, i)) dat |= 1;
        }

        char_ring_buffer_remove(&self.bit_sequence, 8);
        self.byte_sequence[self.byte_seq_len++] = dat;
        if(self.byte_seq_len >= MAX_BYTES){
          // Packet Overized!
          AFSK_Demodulator_reset();
        }

      }

      self.count_last = 0;

    } else
      self.count_last++;

  }

}



