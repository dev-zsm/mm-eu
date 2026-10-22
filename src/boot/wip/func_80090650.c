// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 D_80098180;
f32 __sinf(f32);
void guMtxIdentF(void *, f32);
void guNormalize(f32 *, f32 *, f32 *);
f32 __cosf(f32);

void guRotateF(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 s;
    f32 c;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp28;
    f32 sp24;

    guNormalize(&arg2, &arg3, &arg4);
    arg1 = arg1 * D_80098180;
    s = __sinf(arg1);
    c = __cosf(arg1);
    sp3C = (arg2 * arg3) * (1.0f - c);
    sp38 = (arg3 * arg4) * (1.0f - c);
    sp34 = (arg4 * arg2) * (1.0f - c);
    guMtxIdentF(arg0, arg2);
    sp28 = arg3 * s;
    sp24 = arg4 * s;
    arg0[0x00 / 4] = ((1.0f - arg2 * arg2) * c) + arg2 * arg2;
    arg0[0x24 / 4] = sp38 - arg2 * s;
    arg0[0x18 / 4] = sp38 + arg2 * s;
    arg0[0x14 / 4] = ((1.0f - arg3 * arg3) * c) + arg3 * arg3;
    arg0[0x20 / 4] = sp34 + sp28;
    arg0[0x08 / 4] = sp34 - sp28;
    arg0[0x28 / 4] = ((1.0f - arg4 * arg4) * c) + arg4 * arg4;
    arg0[0x10 / 4] = sp3C - sp24;
    arg0[0x04 / 4] = sp3C + sp24;
}
