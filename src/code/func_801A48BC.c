// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad0[0xC8]; s8 unkC8; } T;
typedef struct { u8 pad0[0x4880]; u32 unk4880; u8 pad4884[0x70]; T *unk48F4; } S;
s32 AudioSeq_GetActiveSeqId(s32);
void AudioThread_QueueCmdS8(s32, s32);
extern S D_801F84B0;
u8 func_801A48BC(void) {
    u8 sp27;
    T *sp1C;
    T *t;
    s8 v;
    sp27 = 0xFF;
    t = D_801F84B0.unk48F4;
    if ((D_801F84B0.unk4880 >> 0x1F) != 0) {
        sp1C = t;
        if (AudioSeq_GetActiveSeqId(3) == 0x5A && (*(u32 *)sp1C >> 0x1F) != 0) {
            v = sp1C->unkC8;
            if (v != -1) {
                sp27 = v;
                AudioThread_QueueCmdS8(0x06030F00, -1);
            }
        }
    }
    return sp27;
}
