// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801FCA68[];

s8 AudioThread_GetSeqPlayerIO(s32 seqPlayerIndex, s32 ioPort) {
    return D_801FCA68[seqPlayerIndex * 0x160 + ioPort];
}
