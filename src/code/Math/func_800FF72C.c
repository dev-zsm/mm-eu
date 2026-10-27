// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
float sqrtf(float);
#pragma intrinsic (sqrtf)
f32 Math_Vec3f_DistXZ(f32 *a0, f32 *a1) {
    f32 dx = a1[0] - a0[0];
    f32 dz = a1[2] - a0[2];
    f32 sum = dx * dx + dz * dz;
    return sqrtf(sum);
}
