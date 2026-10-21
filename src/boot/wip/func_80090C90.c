// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098048;
extern s32 D_A4500010;
extern s32 D_A4500014;

s32 func_80090C90(s32 arg0) {
    s32 *var_a1;
    f32 var_f10;
    s32 var_a0;
    u32 temp_lo;
    u32 temp_v1;

    var_a1 = &D_80098048;
    if (arg0 < 0) {
        var_f10 = (f32) arg0 + 4294967296.0f;
    } else {
        var_f10 = (f32) arg0;
    }
    temp_v1 = (u32) (((f32) *var_a1 / var_f10) + 0.5f);
    if (temp_v1 < 0x84U) {
        return -1;
    }
    temp_lo = temp_v1 / 66U;
    var_a0 = temp_lo & 0xFF;
    if ((temp_lo & 0xFF) >= 0x11) {
        var_a0 = 0x10;
    }
    D_A4500010 = temp_v1 - 1;
    D_A4500014 = var_a0 - 1;
    return *var_a1 / (s32) temp_v1;
}
