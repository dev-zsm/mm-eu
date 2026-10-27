// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u16 D_801F4AE0;
extern u16 D_801CEFFC;
extern void Audio_PlayAmbience(s32 a);
extern void Audio_StartSceneSequence(u16 a);
extern void AudioSeq_QueueSeqCmd(u32 a);

void Audio_PlaySceneSequence(u16 seqId, u8 flag) {
    if (D_801F4AE0 != seqId) {
        if (seqId == 1) {
            Audio_PlayAmbience(8);
        } else if (seqId != 0x57 || D_801CEFFC == 0xFFFF) {
            Audio_StartSceneSequence(seqId);
            AudioSeq_QueueSeqCmd(flag | 0x70040000);
        }
        D_801F4AE0 = seqId;
    }
}
