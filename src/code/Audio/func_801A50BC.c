// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Audio_StopFanfare(u16 duration) {
    AudioSeq_QueueSeqCmd((duration << 16) | 0x100000FF);
    if (AudioSeq_GetActiveSeqId(1) != 0xFFFF) {
        AudioSeq_QueueSeqCmd((duration << 16) | 0x110000FF);
    }
    AudioSeq_QueueSeqCmd((duration << 16) | 0x130000FF);
    AudioSeq_QueueSeqCmd((duration << 16) | 0x140000FF);
    AudioSeq_SetVolumeScale(0, 3, 0x7F, 0);
    AudioSeq_SetVolumeScale(0, 1, 0x7F, 0);
}
