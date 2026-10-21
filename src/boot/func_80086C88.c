// FLAGS: -O2 -g0 -mips2
#include "types.h"

f32 func_80086BA0(f32 y, f32 x);
float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 func_80086C88(f32 x) {
    return func_80086BA0(x, sqrtf(1.0f - x * x));
}
