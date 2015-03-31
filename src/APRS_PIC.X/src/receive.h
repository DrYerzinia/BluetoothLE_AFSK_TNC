#include <stdio.h>
#include <stdint.h>

#include <string.h>

#include "config.h"

#include "AFSK_Demodulator.h"
#include "APRSPacket.h"
#include "crcccitt.h"
#include "base64.h"

#define RECEIVE_PRINT_MODE_DETAILED 0
#define RECEIVE_PRINT_MODE_BASE64   1

void receive_start();
void receive_stop();
void receive_setup();
void receive_process();
