// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Audio_PlayFanfareWithPlayerIOCustomPort(u16 seqId, s8 port, u8 value) {
    AudioSeq_QueueSeqCmd(0x71000000 | (port << 16) | value);
    Audio_PlayFanfare(seqId);
}
