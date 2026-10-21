// FLAGS: -O2 -g0 -mips2
#include "types.h"

float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 func_8008D8A0(f32 x) {
    return sqrtf(x);
}
