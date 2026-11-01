// FLAGS: -O2 -g0 -mips2
#include "sdk/libm.h"

#pragma intrinsic (sqrtf)

f32 sqrtf(f32 x) {
    return sqrtf(x);
}
