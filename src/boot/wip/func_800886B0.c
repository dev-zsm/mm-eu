// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s16 D_80097FCE[];
extern s16 D_800977D0[];
s16 sins(s32 arg0) {
    s16 var_v1;
    u16 var_v0;
    u32 temp_t8;
    temp_t8 = ((u32)(arg0 & 0xFFFF) >> 4) & 0xFFFF;
    var_v0 = temp_t8;
    if (temp_t8 & 0x400) {
        var_v1 = D_80097FCE[-(s32)(temp_t8 & 0x3FF)];
    } else {
        var_v1 = D_800977D0[var_v0 & 0x3FF];
    }
    if (var_v0 & 0x800) {
        return (s16)-var_v1;
    }
    return var_v1;
}
