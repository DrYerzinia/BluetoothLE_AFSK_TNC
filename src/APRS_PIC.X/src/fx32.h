
#include <stdint.h>

typedef int32_t fx32;
typedef	int64_t	fx32d;

#ifndef FX32W
#define FX32W 26
#endif

#define FX32F (32 - FX32W)

#define fx32_one ((fx32)((fx32)1 << FX32F))

#define fx32_from_float(r) ((fx32)(r * fx32_one + (r >= 0 ? 0.5 : -0.5)))
#define fx32_from_int(i) ((fx32d)(i) << FX32F)
#define fx32_to_int(f) ((f) >> FX32F)
#define fx32_add(a, b) (a + b)
#define fx32_sub(a, b) (a - b)
#define fx32_mul(a, b) ((fx32)(((fx32d)(a) * (fx32d)(b)) >> FX32F))
#define fx32_div(a, b) ((fx32)(((fx32d)(a) << FX32F) / (fx32d)(b)))

#define fx32_cmul(a, b) ((fx32)((a * b) >> FX32F))
