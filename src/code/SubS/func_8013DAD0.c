// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

extern s16 Math_Atan2S(f32 dx, f32 dz);

s16 SubS_GetDistSqAndOrientPoints(f32 *a, f32 *b, f32 *distSq) {
    f32 dx = a[0] - b[0];
    f32 dz = a[2] - b[2];

    *distSq = dx * dx + dz * dz;
    return Math_Atan2S(dx, dz);
}
