// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

extern f32 D_80098180;
f32 __sinf(f32);
f32 __cosf(f32);
void guMtxIdentF(f32 mf[4][4]);
void guNormalize(f32 *, f32 *, f32 *);

void guRotateF(f32 mf[4][4], f32 a, f32 x, f32 y, f32 z) {
    f32 sine;
    f32 cosine;
    f32 ab;
    f32 bc;
    f32 ca;
    f32 t;
    f32 xs;
    f32 ys;
    f32 zs;

    guNormalize(&x, &y, &z);
    a = a * D_80098180;
    sine = __sinf(a);
    cosine = __cosf(a);
    ab = x * y * (1 - cosine);
    bc = y * z * (1 - cosine);
    ca = z * x * (1 - cosine);
    guMtxIdentF(mf);
    xs = x * sine;
    ys = y * sine;
    zs = z * sine;
    t = x * x;
    mf[0][0] = (1 - t) * cosine + t;
    mf[2][1] = bc - xs;
    mf[1][2] = bc + xs;
    t = y * y;
    mf[1][1] = (1 - t) * cosine + t;
    mf[2][0] = ca + ys;
    mf[0][2] = ca - ys;
    t = z * z;
    mf[2][2] = (1 - t) * cosine + t;
    mf[1][0] = ab - zs;
    mf[0][1] = ab + zs;
}
