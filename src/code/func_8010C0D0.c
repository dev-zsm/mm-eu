// FLAGS: -O2 -g3 -Wab,-r4300_mul
#include "types.h"
f32 sqrtf(f32);
#pragma intrinsic (sqrtf)
f32 OLib_Vec3fDistXZ(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dz = a[2] - b[2];
    f32 r = dx * dx + dz * dz;
    return sqrtf(r);
}
