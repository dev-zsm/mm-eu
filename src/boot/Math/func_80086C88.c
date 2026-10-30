// FLAGS: -O2 -g0 -mips2
#include "libm.h"

#pragma intrinsic (sqrtf)

f32 Math_FAsinF(f32 x) {
    return Math_FAtan2F(x, sqrtf(1.0f - x * x));
}
