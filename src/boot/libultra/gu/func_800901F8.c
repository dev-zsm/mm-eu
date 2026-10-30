// FLAGS: -O2 -g0 -mips2
#include "gu.h"

void guPosition(Mtx *m, f32 roll, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z) {
    MtxF mf;

    guPositionF(mf, roll, pitch, yaw, scale, x, y, z);
    guMtxF2L(mf, m);
}
