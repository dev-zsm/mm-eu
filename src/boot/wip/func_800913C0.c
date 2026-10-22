// FLAGS: -O2 -g0 -mips2
#include "types.h"

float sqrtf(float);
#pragma intrinsic (sqrtf)

void guNormalize(f32 *a, f32 *b, f32 *c) {
    f32 inv;
    inv = 1.0f / sqrtf(*c * *c + (*a * *a + *b * *b)); *a = *a * inv; *b = *b * inv; *c = *c * inv;
}
