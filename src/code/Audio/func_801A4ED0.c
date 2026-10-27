// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4BEE;
extern void AudioSeq_QueueSeqCmd(u32 cmd);

void Audio_SetSpec(u8 specId) {
    if (D_801F4BEE == 0) {
        AudioSeq_QueueSeqCmd(0xF0000000 | specId);
    } else {
        AudioSeq_QueueSeqCmd(0xF0020000 | specId);
    }
}
