#ifndef DECIMAL_H
#define DECIMAL_H

#include "fx32.h"
typedef fx32 decimal;
#define dmul(a, b) fx32_mul(a, b)
#define dcmul(a, b) fx32_cmul(a, b)
#define ddiv(a, b) fx32_div(a, b)
#define d_from_int(a) fx32_from_int(a)
#define d_from_float(a) fx32_from_float(a)
#define d_to_int(a) fx32_to_int(a)

#endif
