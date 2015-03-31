#include <stdint.h>
#include <stdbool.h>

#include "config.h"

#include "AFSK_Modulator.h"
#include "base64.h"

void transmit_start();
void transmit_stop();
void transmit_setup();
void transmit_send();
bool transmit_process();