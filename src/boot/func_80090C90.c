// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098048[];

s32 func_80090C90(u32 arg0) {
    s32 var_a0;
    u32 temp_lo;
    u32 temp_v1;
    f32 f;

    f = ((f32) D_80098048[0] / (f32) arg0) + 0.5f;
    temp_v1 = (u32) f;
    if (temp_v1 < 0x84U) {
        return -1;
    }
    temp_lo = temp_v1 / 66U;
    var_a0 = temp_lo & 0xFF;
    if ((u8)temp_lo >= 0x11) {
        var_a0 = 0x10;
    }
    *(s32 *)0xA4500010 = temp_v1 - 1;
    *(s32 *)0xA4500014 = var_a0 - 1;
    return D_80098048[0] / (s32) temp_v1;
}
