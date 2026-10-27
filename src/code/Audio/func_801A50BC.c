// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void AudioSeq_QueueSeqCmd(u32 a);
extern s32 AudioSeq_GetActiveSeqId(s32 a);
extern void AudioSeq_SetVolumeScale(s32 a, s32 b, s32 c, s32 d);

void Audio_StopFanfare(u16 arg0) {
    AudioSeq_QueueSeqCmd((arg0 << 16) | 0x100000FF);
    if (AudioSeq_GetActiveSeqId(1) != 0xFFFF) {
        AudioSeq_QueueSeqCmd((arg0 << 16) | 0x110000FF);
    }
    AudioSeq_QueueSeqCmd((arg0 << 16) | 0x130000FF);
    AudioSeq_QueueSeqCmd((arg0 << 16) | 0x140000FF);
    AudioSeq_SetVolumeScale(0, 3, 0x7F, 0);
    AudioSeq_SetVolumeScale(0, 1, 0x7F, 0);
}
