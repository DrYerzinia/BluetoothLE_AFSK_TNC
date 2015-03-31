#include "base64.h"

char base64_digit(uint8_t n){

    if(n < 26) return n + 'A';
    else if(n < 26 + 26) return n - 26 + 'a';
    else if(n < 10 + 26 + 26) return n - 26 - 26 + '0';
    else if(n == 62) return '+';
    else if(n == 63) return '/';

    return 0;

}

uint16_t base64_encode(uint8_t *input, char *output, uint16_t len){

    char *start = output;

    uint16_t i;
    uint8_t l;
    for(i = 0; i < len + 1; i++, input++, output++){
        switch(i % 3){
            case 0:
                if(i < len){
                    *output = base64_digit((*input) >> 2);
                    l = ((*input) & 0x03) << 4;
                }
                break;
            case 1:
                *output = base64_digit(l | ((*input) >> 4));
                l = ((*input) & 0x0F) << 2;
                break;
            case 2:
                *output = base64_digit(l | ((*input) >> 6));
                if(i < len){
                    output++;
                    *output = base64_digit((*input) & 0x3F);
                }
                break;
        }
    }
    *output = '\0';
    switch(2 - ((len - 1) % 3)){
        case 2:
            *output = '=';
            output++;
            *output = '\0';
        case 1:
            *output = '=';
            output++;
            *output = '\0';
            break;
    }

    return (uint16_t)(output - start);

}

unsigned char base64_decode_digit(char c) {

    switch(c){
        case '+' :
            return 62;
        case '/' :
            return 63;
        default  :
            if(c >= 'A' && c <= 'Z') return c - 'A';
            else if(c >= 'a' && c <= 'z') return c - 'a' + 26;
            else if(c >= '0' && c <= '9') return c - '0' + 26 + 26;
    }

    return 0x00;

}

uint16_t base64_decode(char *s) {

    char *p, *q;
    uint8_t bits = 0;
    uint16_t n = 0;
    uint16_t len = 0;

    for(p = s, q = s; *p; p++){

        if(*p == '=') break;
        n = ((n << 6) & 0xFFC0) + (base64_decode_digit(*p) & 0x3F);
        bits += 6;
        if(bits >= 8){
            bits -= 8;
            *q = (n >> bits) & 0xFF;
            q++;
            len++;
        }

    }

    return len;

}
