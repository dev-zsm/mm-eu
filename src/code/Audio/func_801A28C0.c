// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSeq_QueueSeqCmd(u32 cmd);
u16 AudioSeq_GetActiveSeqId(s32 seqPlayerIndex);
void AudioSeq_SetVolumeScale(s32 seqPlayerIndex, s32 a, s32 b, u8 c);
void Audio_SplitBgmChannels(s32 a);

void Audio_StopSequenceAtPos(u8 seqPlayerIndex, u8 arg1) {
    AudioSeq_QueueSeqCmd(((u32)seqPlayerIndex << 24) | 0x100000FF | 0x140000);
    if (seqPlayerIndex == 3) {
        if (AudioSeq_GetActiveSeqId(0) != 0xFFFF) {
            AudioSeq_SetVolumeScale(0, 3, 0x7F, arg1);
            Audio_SplitBgmChannels(0);
        }
    }
}
