/**
 * @file	AFSK_Demodulator.h
 * @author	Michael Marques <dryerzinia@gmail.com>
 * @brief	Demodulator for AFSK modulated AX.25 Frames.
 * @ingroup Packet
 *
 * This file contains a struct AFSK_Demodulator for holding all the data
 * necessary for the AFSK_Demodulator process byte function which takes in 8
 * bit signed samples from an audio signal.
 */

#ifndef AFSK_DEMODULATOR_H
#define AFSK_DEMODULATOR_H

// malloc, free, int types, boolean's
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// memcpy for generating packet data to return
#include <string.h>

#include <ctype.h>

#include <math.h>

#include "decimal.h"

#include "char_ring_buffer.h"
#include "decimal_ring_buffer.h"

#ifndef PI
#define PI 3.14159265359
#endif

#define MAX_BYTES 255

#define WINDOW 9

#define FREQUENCY0 1200
#define FREQUENCY1 2200

#define SAMPLE_RATE 11025
#define BIT_RATE 1200

#define BIT_WIDTH SAMPLE_RATE/BIT_RATE

/**
 * @ingroup Packet
 * Contains all information necessary to demodulate AFSK modulated AX-25 frames
 */
typedef struct {

  /**
   * Buffer to hold incoming data until there is enough to fill the window
   * and calculate Fourier Coefficients
   */
  decimal_ring_buffer input_buffer;

  /**
   * Buffer of Fourier Coefficients so we can average them and smooth out
   * the signal for extracting bits from Zero-Crossings
   */
  decimal fcd_filt;

  /**
   * Goertzel Coefficient for calculating magnitude of frequency 0
   */
  decimal coeff0;
  /**
   * Goertzel Coefficient for calculating magnitude of frequency 1
   */
  decimal coeff1;

  /**
   * Count of samples since last Zero-Crossing
   */
  uint16_t count_last;

  /**
   * A 14 character ring buffer for Bit Data
   * Stores currently demodulated bits after Bit Stuffing removal and
   * NRZI decoding
   * The highest number of bits that should be collected before they are
   * pushed to the byte array is 12, 8 for a byte + 6 from bit stuffing
   */
  char_ring_buffer bit_sequence;

  /**
   * Value of the last bit to be decoded
   * used to check if there has been a Zero-Crossing
   */
  uint8_t last_bit;

  /**
   * Indicator if bit stuffing is occurring
   * TODO: same as above
   */
  bool bit_stuffing;

  /**
   * Expandable array containing the sequence of bytes in the received packet
   * It has a default size of 330 to contain a standard APRS packet without
   * any reallocations
   */
  uint16_t byte_seq_len;
  char byte_sequence[MAX_BYTES];

} AFSK_Demodulator;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup Packet
 * Set up the demodulator with parameters for the type of signal to receive
 */
void AFSK_Demodulator_init();

/**
 * @ingroup Packet
 * Pass another byte of signal data to the demodulator
 * @returns a pointer to a char array containing a demodulated packet
 *  if this byte did not complete demodulation of a packet it returns a
 *  NULL pointer instead
 */
void AFSK_Demodulator_proccess_byte(int8_t data_point, uint8_t * new_data);

/**
 * @ingroup Packet
 * Adjust the bit rate of the incoming data
 * This function resets the window width so these parameters cannot be
 * adjusted directly
 */
void AFSK_Demodulator_set_bit_rate(uint16_t br);

#ifdef __cplusplus
}
#endif

#endif

