// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801FC878[];
extern s32 AudioLoad_GetRealTableIndex(s32 tableType, s32 id);
extern s32 AudioLoad_SyncLoad(s32 tableType, s32 id, s32 *status);

s32 AudioLoad_SyncLoadSeq(s32 seqId) {
    s32 pad; // keeps status at the ROM stack offset
    s32 status;

    if (D_801FC878[AudioLoad_GetRealTableIndex(0, seqId)] == 1) {
        return 0;
    }
    return AudioLoad_SyncLoad(0, seqId, &status);
}
