// FLAGS: -O2 -g0 -mips2

#include "types.h"

s32 func_80096500(void*, s32, s32);
s32 PadMgr_VoiceAcquireSerialEventQueue();
void PadMgr_VoiceReleaseSerialEventQueue(s32);
void func_801A60C0(s32, s32);

extern s32 D_801F4DE0;
extern u8 D_801F4DF8[];

void func_801A62EC(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;

    if (D_801F4DE0 != 0) {
        sp18 = PadMgr_VoiceAcquireSerialEventQueue();
        sp1C = func_80096500(D_801F4DF8, arg0, arg1);
        PadMgr_VoiceReleaseSerialEventQueue(sp18);
        if (sp1C != 0) {
            // the u64 cast is needed: it makes the ROM test and pass the value through the same register
            func_801A60C0((u64)sp1C, sp1C);
        }
    }
}
