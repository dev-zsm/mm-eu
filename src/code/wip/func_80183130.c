// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 xx, yx, zx, pad0C, xy, yy, zy, pad1C, xz, yz, zz;
} Mtx3;

float sqrtf(float);
#pragma intrinsic (sqrtf)

extern Mtx3 *D_801F3644;

void Matrix_ReplaceRotation(Mtx3 *a0) {
    f32 a, b, c, t;
    Mtx3 *m = D_801F3644;

    a = m->xx;
    b = m->yx;
    c = m->zx;
    t = sqrtf(a * a + b * b + c * c);
    m->xx = a0->xx * t;
    m->yx = a0->yx * t;
    m->zx = a0->zx * t;
    a = m->xy;
    b = m->yy;
    c = m->zy;
    t = sqrtf(a * a + b * b + c * c);
    m->xy = a0->xy * t;
    m->yy = a0->yy * t;
    m->zy = a0->zy * t;
    a = m->xz;
    b = m->yz;
    c = m->zz;
    t = sqrtf(a * a + b * b + c * c);
    m->xz = a0->xz * t;
    m->yz = a0->yz * t;
    m->zz = a0->zz * t;
}
