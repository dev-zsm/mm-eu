// FLAGS: -O2 -g0 -mips2
#include "gu.h"

void guLookAtHilite(Mtx *m, LookAt *l, Hilite *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                    f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight) {
    MtxF mf;

    guLookAtHiliteF(mf, l, h, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp, xl1, yl1, zl1, xl2, yl2, zl2, twidth,
                    theight);
    guMtxF2L(mf, m);
}
