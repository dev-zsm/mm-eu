// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 pad0[8];
    f64 unk8;
    f64 unk10;
    f64 unk18;
    f64 unk20;
} SinPoly800997D0;
extern SinPoly800997D0 D_800997D0;
extern f64 D_800997F8;
extern f64 D_80099800;
extern f64 D_80099808;
extern f32 D_80099810;
extern f32 D_80099820;
f32 __cosf(f32 x) {
    f32 absx;
    f64 dx;
    f64 xSq;
    f64 polyApprox;
    f64 *new_var;
    f64 dn;
    s32 n;
    f64 result;
    s32 ix = *((s32 *) (&x));
    s32 xpt = (ix >> 22) & 0x1FF;
    if (310 > xpt) {
        if (0.0f < x) {
            absx = x;
        } else {
            absx = -x;
        }
        dx = absx;
        dn = (dx * D_800997F8) + 0.5;
        if (dn >= 0.0) {
            n = (s32) (dn + 0.5);
        } else {
            n = (s32) (dn - 0.5);
        }
        new_var = &D_800997D0.unk8;
        dn = n;
        dn -= 0.5;
        dx -= dn * D_80099800;
        dx -= dn * D_80099808;
        xSq = dx * dx;
        polyApprox = (((((D_800997D0.unk20 * xSq) + D_800997D0.unk18) * xSq) + D_800997D0.unk10) * xSq) + (*new_var);
        result = dx + ((dx * xSq) * polyApprox);
        if (!(n & 1)) {
            return (f32) result;
        }
        return -((f32) result);
    }
    if (x != x) {
        return D_80099820;
    }
    return D_80099810;
}
