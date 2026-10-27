// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 sqrtf(f32);
#pragma intrinsic (sqrtf)

f32 Math_Vec3f_DistXZAndStore(f32 *a, f32 *b, f32 *dx, f32 *dz) {
    *dx = b[0] - a[0];
    *dz = b[2] - a[2];
    return sqrtf(*dx * *dx + *dz * *dz);
}
