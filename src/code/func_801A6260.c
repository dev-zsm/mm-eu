// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { s32 pad0[2]; s32 unk8; } S;
s32 PadMgr_VoiceAcquireSerialEventQueue();
void func_800965B0(void *);
void PadMgr_VoiceReleaseSerialEventQueue(s32);
extern S D_801F4DE0;
extern u8 D_801F4DF8[];
s32 func_801A6260(void) {
    s32 sp1C;
    s32 sp18;
    sp1C = D_801F4DE0.unk8;
    D_801F4DE0.unk8 = 0;
    sp18 = PadMgr_VoiceAcquireSerialEventQueue();
    func_800965B0(D_801F4DF8);
    PadMgr_VoiceReleaseSerialEventQueue(sp18);
    return sp1C;
}
