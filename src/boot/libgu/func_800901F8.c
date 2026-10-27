// FLAGS: -O2 -g0 -mips2
#include "types.h"

void guPositionF(f32 *m, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz);
void guMtxF2L(f32 *m, s32 arg);

void guPosition(s32 arg0, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz) {
    f32 sp28[16];

    guPositionF(sp28, x, y, z, s, tx, ty, tz);
    guMtxF2L(sp28, arg0);
}
