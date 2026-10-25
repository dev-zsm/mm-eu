// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void Audio_PlayFanfare(u16);
extern void AudioSeq_QueueSeqCmd();

void Audio_PlayFanfareWithPlayerIOPort7(u16 arg0, u8 arg1) {
    Audio_PlayFanfare(arg0);
    AudioSeq_QueueSeqCmd(arg1 | 0x71070000);
}
