// FLAGS: -O2 -g0 -mips2
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

f32 func_800920E0(f32 arg0) {
    f32 ax;
    f64 t12;
    f64 t14;
    f64 t0;
    f64 t2;
    f64 t14sq;
    f64 poly;
    s32 ix;
    s32 n;

    ix = *(s32 *)&arg0;
    if (((ix >> 22) & 0x1FF) < 0x136) {
        if (0.0f < arg0) {
            ax = arg0;
        } else {
            ax = -arg0;
        }
        t12 = (f64)ax;
        t14 = (t12 * D_800997F8) + 0.5;
        if (t14 >= 0.0) {
            n = (s32)(t14 + 0.5);
        } else {
            n = (s32)(t14 - 0.5);
        }
        t0 = (f64)n - 0.5;
        t2 = (t12 - (t0 * D_80099800)) - (t0 * D_80099808);
        t14sq = t2 * t2;
        poly = D_800997D0.unk8 + (((((D_800997D0.unk20 * t14sq) + D_800997D0.unk18) * t14sq) + D_800997D0.unk10) * t14sq);
        if (!(n & 1)) {
            return (f32)((t2 * t14sq * poly) + t2);
        }
        return -(f32)((t2 * t14sq * poly) + t2);
    }
    if (arg0 != arg0) {
        return D_80099820;
    }
    return D_80099810;
}
