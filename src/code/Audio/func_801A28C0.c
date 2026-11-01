// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"


void Audio_StopSequenceAtPos(u8 seqPlayerIndex, u8 arg1) {
    AudioSeq_QueueSeqCmd(((u32)seqPlayerIndex << 24) | 0x100000FF | 0x140000);
    if (seqPlayerIndex == 3) {
        if (AudioSeq_GetActiveSeqId(0) != 0xFFFF) {
            AudioSeq_SetVolumeScale(0, 3, 0x7F, arg1);
            Audio_SplitBgmChannels(0);
        }
    }
}
