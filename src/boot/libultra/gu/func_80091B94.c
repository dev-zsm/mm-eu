// FLAGS: -O2 -g0 -mips2
#include "gu.h"

void guOrtho(Mtx *m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    MtxF mf;

    guOrthoF(mf, l, r, b, t, n, f, scale);
    guMtxF2L(mf, m);
}
