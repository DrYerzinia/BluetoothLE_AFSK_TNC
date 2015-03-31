/**
 * @file	APRSPacket.c
 * @author	Michael Marques <dryerzinia@gmail.com>
 */

#include "APRSPacket.h"

void APRSPacket_from_data(APRSPacket *packet, uint8_t * data, uint16_t len){

	int i;

	packet->len = len;
        memcpy(&packet->data, data, len);

	for(i = 0; i < 7; i++) packet->destination_address[i] = (signed char)((unsigned char)(data[i])>>1);
	packet->destination_address[7] = '\0';

	for(i = 7; i < 14; i++) packet->source_address[i-7] = (signed char)((unsigned char)(data[i])>>1);
	packet->source_address[7] = '\0';

	packet->repeaters = 0;

        int n = 14;
	while(true){

		if(n+1 >= len) break;

		// Check for 0 bit set on end of last address character indicating that there are no more repeater addresses
		if((data[n-1] & 0x01) != 0) break;

		if(packet->repeaters > 7) break;

		if(n+7 >= len) break;

		signed char* new_address = packet->repeater_addresses[packet->repeaters];
		for(i = n; i < n+7; i++) new_address[i-n] = (signed char)((unsigned char)(data[i])>>1);
		new_address[7] = '\0';
		n+=7;

		packet->repeaters++;

	}

}

uint16_t APRSPacket_crc(APRSPacket *packet){

	return CRCCCITT((uint8_t*) packet->data, packet->len - 2, APRS_CRC_POLY);

}

uint16_t APRSPacket_data_crc(APRSPacket *packet){

    uint16_t crc = packet->data[packet->len - 1];
    crc <<= 8;
    crc |= packet->data[packet->len - 2] & 0xFF;
    return crc;

}

bool APRSPacket_crc_is_valid(APRSPacket *packet){
    return APRSPacket_crc(packet) == APRSPacket_data_crc(packet);
}

void APRSPacket_print_detailed(APRSPacket *packet){

        int i;

        uint16_t calculated_crc = APRSPacket_crc(packet);
        uint16_t crc = APRSPacket_data_crc(packet);

        printf("Packet Received\n");

        if(calculated_crc != crc)
                printf("Checksum Error!\nCaluclated checksum is: %04X\n", calculated_crc);

        printf("Size: %d\n", packet->len);
        printf("Destination Address: %s\n", packet->destination_address);
        printf("Source Address: %s\n", packet->source_address);
        for(i = 0; i < packet->repeaters; i++)
                printf("Repeater-%d: %s\n", i+1, packet->repeater_addresses[i]);

        printf("\nData: \n");

        i = 0;
        while(i < packet->len){
                int j;
                for(j = 0; j < 20; j++){
                        if(i < packet->len){
                                if(isprint(packet->data[i])) putchar(packet->data[i]);
                                else printf(".");
                        } else putchar(' ');
                        i++;
                }
                i -= 20;
                printf("  |  ");
                for(j = 0; j < 20; j++){
                        if(i < packet->len){
                                unsigned char val = packet->data[i];
                                printf(" %02X", (int)val);
                                i++;
                        }
                }
                putchar('\n');
        }

        printf("\nChecksum: %04X\n\n", crc);

}