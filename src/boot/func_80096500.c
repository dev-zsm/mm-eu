// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
typedef struct { s32 unk0; s32 unk4; } Dev;
extern u8 D_80098410[];
s32 __osVoiceSetADConverter(s32 a0, s32 a1, u8 a2);
s32 osVoiceControlGain(Dev *arg0, s32 arg1, s32 arg2) {
    s32 ret;
    u8 data;
    if (arg1 == 0) { data = 0x18; } else { data = 0x98; }
    ret = __osVoiceSetADConverter(arg0->unk0, arg0->unk4, data);
    if (ret != 0) { return ret; }
    if (arg2 < 8 && arg2 >= 0) {
        data = D_80098410[arg2] + 2;
    } else { return 5; }
    ret = __osVoiceSetADConverter(arg0->unk0, arg0->unk4, data);
    if (ret != 0) { return ret; }
    return ret;
}
