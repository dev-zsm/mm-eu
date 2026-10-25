// FLAGS: -O2 -g0 -mips2
#include "types.h"

void Audio_StartMorningSceneSequence(u16 seqId);
void AudioSeq_QueueSeqCmd(u32 cmd);

void Audio_PlayMorningSceneSequence(u16 arg0, u8 arg1) {
    Audio_StartMorningSceneSequence(arg0);
    AudioSeq_QueueSeqCmd(arg1 | 0x70040000);
}
