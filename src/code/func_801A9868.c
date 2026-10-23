// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801D3DF0;
extern s32 D_801F7580[];
void AudioSeq_QueueSeqCmd(s32 a0) {
    u8 v = D_801D3DF0;
    D_801F7580[v] = a0;
    D_801D3DF0 = v + 1;
}
