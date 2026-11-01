// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

extern u16 D_801F4AE0;
extern u16 D_801CEFFC;

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
