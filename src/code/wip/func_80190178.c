// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 AudioLoad_GetRealTableIndex(s32);
extern u8 D_801FC878[];

/* best attempt: 2 instructions differ (ROM copies seqId into a1 before indexing; the extra parameter only approximates it) */
s32 AudioLoad_IsSeqLoadComplete(s32 seqId, s32 arg1) {
    if (seqId == 0xFF) {
        return 1;
    } else if (D_801FC878[seqId] >= 2) {
        return 1;
    } else if (D_801FC878[AudioLoad_GetRealTableIndex(0)] >= 2) {
        return 1;
    } else {
        return 0;
    }
}
