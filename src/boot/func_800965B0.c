// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Dev;
s32 func_800928D0(s32 a0, s32 a1, u8 *a2);
s32 func_80089720(Dev *a0, u8 *a1);
s32 func_800966E0(s32 a0, s32 a1, s32 a2, s32 *a3);
s32 func_800965B0(Dev *arg0) {
    s32 temp_v0;
    u8 sp2B;
    s32 sp24;
    s32 var_v1;
    temp_v0 = func_800928D0(arg0->unk0, arg0->unk4, &sp2B);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (sp2B & 2) {
        return 0xF;
    }
    if (arg0->unk8 != 0) {
        return 5;
    }
    sp24 = 0x05000000;
    var_v1 = func_800966E0(arg0->unk0, arg0->unk4, 0, &sp24);
    if (var_v1 == 0) {
        var_v1 = func_80089720(arg0, &sp2B);
        if (var_v1 & 0xFF00) {
            var_v1 = 5;
        } else {
            arg0->unk8 = 1;
        }
    }
    return var_v1;
}
