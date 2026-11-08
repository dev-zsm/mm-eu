// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Audio_PlayMorningSceneSequence(u16 seqId, u8 dayMinusOne) {
    Audio_StartMorningSceneSequence(seqId);
    AudioSeq_QueueSeqCmd(dayMinusOne | 0x70040000);
}
