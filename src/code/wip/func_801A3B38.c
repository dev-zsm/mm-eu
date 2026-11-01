// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801CF030[];
void Audio_PlayFanfare(u16);
void Audio_PlaySequenceWithSeqPlayerIO(s32, u16, s32, s32, s32);
void AudioSeq_QueueSeqCmd(u32);
void AudioSeq_SetVolumeScale(s32, s32, s32, s32);
void Audio_PlaySequenceInCutscene(u16 seqId) {
    if (D_801CF030[(u8)seqId] & 2) {
        Audio_PlayFanfare(seqId);
    } else if (D_801CF030[(u8)seqId] & 4) {
        AudioSeq_QueueSeqCmd(seqId | 0x01000000);
    } else if (D_801CF030[(u8)seqId] & 0x80) {
        AudioSeq_QueueSeqCmd(seqId | 0x03000000);
    } else {
        Audio_PlaySequenceWithSeqPlayerIO(0, seqId, 0, 7, 0xFF);
        AudioSeq_SetVolumeScale(0, 1, 0x7F, 0);
        AudioSeq_SetVolumeScale(0, 3, 0x7F, 0);
        AudioSeq_QueueSeqCmd(0x110000FF);
    }
}
