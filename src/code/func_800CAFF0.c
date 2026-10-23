// FLAGS: -O2 -g3 -Wab,-r4300_mul
#include "types.h"
f32 sqrtf(f32);
#pragma intrinsic (sqrtf)
f32 func_800CAFF0(f32 *v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    return sqrtf(x * x + y * y + z * z);
}
