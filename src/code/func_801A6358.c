// FLAGS: -O2 -g0 -mips2
#include "types.h"
s32 func_80095E10(s32);
s32 PadMgr_VoiceAcquireSerialEventQueue();
void PadMgr_VoiceReleaseSerialEventQueue(s32);
s32 func_801A6358(s32 arg0) {
    s32 sp1C;
    s32 sp18;
    sp18 = PadMgr_VoiceAcquireSerialEventQueue();
    sp1C = func_80095E10(arg0);
    PadMgr_VoiceReleaseSerialEventQueue(sp18);
    return sp1C;
}
