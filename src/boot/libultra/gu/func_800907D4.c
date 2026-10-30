// FLAGS: -O2 -g0 -mips2
#include "gu.h"

void guRotate(Mtx *m, f32 a, f32 x, f32 y, f32 z) {
    MtxF mf;

    guRotateF(mf, a, x, y, z);
    guMtxF2L(mf, m);
}
