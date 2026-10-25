// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

extern s16 func_80180F74(f32 dx, f32 dz);

s16 SubS_GetDistSqAndOrientPoints(f32 *a, f32 *b, f32 *distSq) {
    f32 dx = a[0] - b[0];
    f32 dz = a[2] - b[2];

    *distSq = dx * dx + dz * dz;
    return func_80180F74(dx, dz);
}
