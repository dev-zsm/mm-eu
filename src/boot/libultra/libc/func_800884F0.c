// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
// COMPILER: ido53
#include "types.h"

extern f64 D_800995F0[];
extern f64 D_80099618;
extern f64 D_80099620;
extern f64 D_80099628;
extern f32 D_80099630;
extern f32 D_80099820;

f32 __sinf(f32 x) {
    f64 dx;
    f64 xSq;
    f64 polyApprox;
    f64 dn;
    s32 n;
    f64 result;
    s32 ix;
    s32 xpt;
    s32 raw;

    raw = *(s32 *)&x;
    xpt = (raw >> 22) & 0x1FF;
    ix = xpt;

    if (xpt < 255) {
        dx = x;
        if (xpt >= 230) {
            xSq = dx * dx;
            polyApprox = (((((D_800995F0[4] * xSq) + D_800995F0[3]) * xSq) + D_800995F0[2]) * xSq) + D_800995F0[1];
            result = (dx * xSq * polyApprox) + dx;
            return (f32)result;
        }
        return x;
    }
    if (ix < 310) {
        dx = x;
        dn = dx * D_80099618;
        if (dn >= 0.0) {
            n = (s32)(dn + 0.5);
        } else {
            n = (s32)(dn - 0.5);
        }
        dn = n;
        dx -= dn * D_80099620;
        dx -= dn * D_80099628;
        xSq = dx * dx;
        polyApprox = (((((D_800995F0[4] * xSq) + D_800995F0[3]) * xSq) + D_800995F0[2]) * xSq) + D_800995F0[1];
        result = (dx * xSq * polyApprox) + dx;
        if (!(n & 1)) {
            return (f32)result;
        }
        return -(f32)result;
    }
    if (x != x) {
        return D_80099820;
    }
    return D_80099630;
}
