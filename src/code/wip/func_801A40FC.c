// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSeq_QueueSeqCmd(u32 cmd);

void Audio_PlaySequenceWithSeqPlayerIO(s8 player, u16 seqId, u8 fadeIn, s8 ioPort, u8 ioData) {
    s32 hi = player << 24;
    u16 id;

    AudioSeq_QueueSeqCmd(hi | 0x70000000 | (ioPort << 16) | ioData);
    if ((seqId & 0xFF) < 2) {
        id = seqId;
    } else {
        id = seqId | 0x8000;
    }
    AudioSeq_QueueSeqCmd((fadeIn << 16) | hi | id);
}
