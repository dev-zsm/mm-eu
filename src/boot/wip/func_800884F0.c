// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f64 D_800995F0[];
extern f64 D_80099618;
extern f64 D_80099620;
extern f64 D_80099628;
extern f32 D_80099630;
extern f32 D_80099820;

f32 func_800884F0(f32 arg0) {
    f64 temp_f0;
    f64 temp_f12;
    f64 temp_f14;
    f64 temp_f2;
    s32 temp_t6;
    s32 var_v0;

    temp_t6 = ((*(s32 *)&arg0) >> 0x16) & 0x1FF;
    if (temp_t6 < 0xFF) {
        temp_f2 = (f64) arg0;
        if (temp_t6 >= 0xE6) {
            temp_f12 = temp_f2 * temp_f2;
            return (f32) ((temp_f2 * temp_f12 * (D_800995F0[1] + (((((D_800995F0[4] * temp_f12) + D_800995F0[3]) * temp_f12) + D_800995F0[2]) * temp_f12))) + temp_f2);
        }
        return arg0;
    }
    if (temp_t6 < 0x136) {
        temp_f0 = temp_f2 * D_80099618;
        if (temp_f0 >= 0.0) {
            var_v0 = (s32) (temp_f0 + 0.5);
        } else {
            var_v0 = (s32) (temp_f0 - 0.5);
        }
        temp_f0 = (f64) var_v0;
        temp_f2 = (temp_f2 - (temp_f0 * D_80099620)) - (temp_f0 * D_80099628);
        temp_f12 = temp_f2 * temp_f2;
        temp_f14 = D_800995F0[1] + (((((D_800995F0[4] * temp_f12) + D_800995F0[3]) * temp_f12) + D_800995F0[2]) * temp_f12);
        if (!(var_v0 & 1)) {
            return (f32) ((temp_f2 * temp_f12 * temp_f14) + temp_f2);
        }
        return -(f32) ((temp_f2 * temp_f12 * temp_f14) + temp_f2);
    }
    if (arg0 != arg0) {
        return D_80099820;
    }
    return D_80099630;
}
