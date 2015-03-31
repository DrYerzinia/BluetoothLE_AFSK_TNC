#ifndef SPI_H
#define	SPI_H

#include <stdlib.h>
#include <stdint.h>

#include "main.h"

#define SCK1RP 8
#define SDO1RP 7

uint8_t spi_transfer(uint8_t data);
void spi_cs(uint8_t state);

void spi_slave_init();
void spi_master_init();

#endif