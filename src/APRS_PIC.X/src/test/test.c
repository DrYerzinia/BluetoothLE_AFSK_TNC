#include <stdio.h>
#include <stdint.h>

#include <ctype.h>
#include <string.h>

#include "../base64.h"

const char test1[] = "gqCkpkBA4paIYK6OrGfwA1Rlc3Rpbmc67w==";

const char test1_res[] =
	{
		0x82, 0xa0, 0xa4, 0xa6, '@', '@', 0xe2, 0x96, 0x88, 0x60, 
		0xae, 0x8e ,0xac, 'g', 0xf0, 0x03, 'T', 'e', 's', 't',
		'i', 'n', 'g', ':', 0xef
	};

void print_data(const char *buffer, uint16_t len){

	int i = 0;
        while(i < len){
                int j;
                for(j = 0; j < 20; j++){
                        if(i < len){
                                if(isprint(buffer[i])) putchar(buffer[i]);
                                else printf(".");
                        } else putchar(' ');
                        i++;
                }
                i -= 20;
                printf("  |  ");
                for(j = 0; j < 20; j++){
                        if(i < len){
                                unsigned char val = buffer[i];
                                printf(" %02X", (int)val);
                                i++;
                        }
                }
                putchar('\n');
        }

}

void main(void){

	char buffer[1000];

	memcpy(buffer, test1, strlen(test1) + 1);

	uint16_t len = base64_decode(buffer);

	uint8_t res = memcmp(buffer, test1_res, len);
	print_data(buffer, len);
	print_data(test1_res, len);


	printf("Test: %d\n", res);

}
