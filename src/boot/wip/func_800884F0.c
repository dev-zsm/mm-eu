// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
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
    f64 poly;
    f64 dn;
    f64 result;
    s32 n;
    s32 ix;
    s32 xpt;

    ix = *(s32 *)&x;
    xpt = (ix >> 0x16) & 0x1FF;
    if (xpt < 0xFF) {
        dx = x;
        if (xpt >= 0xE6) {
            xSq = dx * dx;
            poly = D_800995F0[1] + (((((D_800995F0[4] * xSq) + D_800995F0[3]) * xSq) + D_800995F0[2]) * xSq);
            result = (dx * xSq * poly) + dx;
            return result;
        }
        return x;
    }
    if (xpt < 0x136) {
        dx = x;
        dn = dx * D_80099618;
        if (dn >= 0.0) {
            n = dn + 0.5;
        } else {
            n = dn - 0.5;
        }
        dn = n;
        dx = (dx - (dn * D_80099620)) - (dn * D_80099628);
        xSq = dx * dx;
        poly = D_800995F0[1] + (((((D_800995F0[4] * xSq) + D_800995F0[3]) * xSq) + D_800995F0[2]) * xSq);
        result = (dx * xSq * poly) + dx;
        if (!(n & 1)) {
            return result;
        }
        return -(f32)result;
    }
    if (x != x) {
        return D_80099820;
    }
    return D_80099630;
}
