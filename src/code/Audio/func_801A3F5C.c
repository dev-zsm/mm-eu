// FLAGS: -O2 -g0
#include "types.h"
extern s8 D_801F4BEB;
extern u16 D_801F4BEC;
u16 AudioSeq_GetActiveSeqId(s32);
u8 *AudioThread_GetFontsForSequence(s32, void *);
void AudioSeq_QueueSeqCmd(u32);
void Audio_PlayFanfare(u16 arg0) {
    u16 sp26;
    s32 sp20;
    u8 *sp1C;
    u8 *other;
    sp26 = AudioSeq_GetActiveSeqId(1);
    sp1C = AudioThread_GetFontsForSequence(sp26 & 0xFF, &sp20);
    other = AudioThread_GetFontsForSequence(arg0 & 0xFF, &sp20);
    if (sp26 == 0xFFFF || *sp1C == *other) {
        D_801F4BEB = 1;
    } else {
        D_801F4BEB = 5;
        AudioSeq_QueueSeqCmd(0x110000FF);
    }
    D_801F4BEC = arg0;
}
