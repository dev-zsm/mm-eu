// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { s32 unk0; s32 unk4; } Dev;
extern u8 D_80098410[];
s32 __osVoiceSetADConverter(s32 a0, s32 a1, s32 a2, Dev *a3);
s32 osVoiceControlGain(Dev *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    if (arg1 == 0) {
        var_a2 = 0x18;
    } else {
        var_a2 = 0x98;
    }
    temp_v0 = __osVoiceSetADConverter(arg0->unk0, arg0->unk4, var_a2, arg0);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (arg2 < 8 && arg2 >= 0) {
        temp_v1 = __osVoiceSetADConverter(arg0->unk0, arg0->unk4, (D_80098410[arg2] + 2) & 0xFF, arg0);
        if (temp_v1 != 0) {
            return temp_v1;
        }
        return temp_v1;
    }
    return 5;
}
