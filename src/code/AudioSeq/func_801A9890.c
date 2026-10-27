// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801D3DF0;
extern u8 D_801D3DF4;
extern s32 D_801F7580[];
void AudioSeq_ProcessSeqCmd(s32);
void AudioSeq_ProcessSeqCmds(void) {
    while (D_801D3DF0 != D_801D3DF4) { AudioSeq_ProcessSeqCmd(D_801F7580[D_801D3DF4++]); }
}
