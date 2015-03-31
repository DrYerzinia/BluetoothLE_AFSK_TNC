/**
 * @file    console.c
 * @author  Michael Marques <dryerzinia@gmail.com>
 * @brief   Serial interrupts and routines for communication
 * @ingroup Interface
 *
 * Serial interrupts and routines for communication
 */

#include <stdlib.h>
#include <stdint.h>

#include "config.h"

#ifndef CONSOLE_H
#define	CONSOLE_H

#define U1TXRP 3

int putch(int c);
void console_init();

#endif	/* PRINTF_ROUTE_H */

