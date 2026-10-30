// FLAGS: -O2 -g0 -mips2
#include "gu.h"

void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    MtxF mf;

    func_8008ABF0(mf, perspNorm, fovy, aspect, near, far, scale);
    guMtxF2L(mf, m);
}
