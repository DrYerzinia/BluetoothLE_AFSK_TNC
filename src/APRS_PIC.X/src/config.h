#ifndef CONFIG_H
#define	CONFIG_H

#include <p33FJ64GP802.h>

#define FCY 39613750ULL

#include <libpic30.h>

#define U1BAUDRATE  115200
#define U1BRGVAL    ((FCY/U1BAUDRATE)/4)-1

#endif	/* CONFIG_H */

