// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Audio_PlayFanfareWithPlayerIOPort7(u16 seqId, u8 ioData) {
    Audio_PlayFanfare(seqId);
    AudioSeq_QueueSeqCmd(ioData | 0x71070000);
}
