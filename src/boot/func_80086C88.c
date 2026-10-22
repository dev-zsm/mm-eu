// FLAGS: -O2 -g0 -mips2
#include "types.h"

f32 Math_FAtan2F(f32 y, f32 x);
float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 Math_FAsinF(f32 x) {
    return Math_FAtan2F(x, sqrtf(1.0f - x * x));
}
