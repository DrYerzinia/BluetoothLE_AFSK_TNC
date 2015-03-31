/**
 * @file	APRSPacket.h
 * @author	Michael Marques <dryerzinia@gmail.com>
 * @brief	Contains functions for parsing APRS data from packets and
 * 			structs for storing that data
 * @ingroup	Packet
 *
 * File contains all the necessary functions for parsing APRS packets.
 * Contains structs for storing the APRS related data, and functions
 * for accessing it and converting it to string form for printing.
 */

#ifndef APRSPACKET_H
#define APRSPACKET_H

#define MAX_APRS_PACKET_SIZE 256


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <ctype.h>
#include <string.h>

#include "crcccitt.h"

/**
 * Value of CRC Polynomial used in AX-25
 */
#define APRS_CRC_POLY 0x8408

/**
 * @ingroup Packet
 * Contains all information related to the APRS packet include the raw data,
 * the AX-25 Addresses, and any parsed information based on standard APRS
 * messages
 */
typedef struct {

	/**
	 * Raw data of APRS packet including CRC
	 */
	uint8_t data[MAX_APRS_PACKET_SIZE];
        uint16_t len;

	/**
	 * Destination address of packet with SSID
	 * May contain Mic-E data
	 */
	int8_t destination_address[8];
	/**
	 * Source of the packet with SSID
	 */
	int8_t source_address[8];

	/**
	 * Number of repeaters
	 * A maximum of 8 repeaters is allowed
	 */
	uint8_t repeaters;
	/**
	 * List of repeaters
         * Up to 8 repeaters
	 */
	int8_t repeater_addresses[8][8];

} APRSPacket;

/**
 * @ingroup Packet
 * Creates an APRSPacket strut from a char array of packet data parsing any
 * relevant information for easier access later.
 */
void APRSPacket_from_data(APRSPacket *packet, uint8_t *data, uint16_t len);

/**
 * @ingroup Packet
 * Calculates CRC of packet data using the APRS_CRC_POLY
 * @returns CRC value of packet data
 */
uint16_t APRSPacket_crc(APRSPacket *packet);

uint16_t APRSPacket_data_crc(APRSPacket *packet);

bool APRSPacket_crc_is_valid(APRSPacket *packet);

void APRSPacket_print_detailed(APRSPacket *packet);

#endif
