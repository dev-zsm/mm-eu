// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801FC818[];

s32 AudioLoad_GetRealTableIndex(s32, s32);

s32 AudioLoad_IsSampleLoadComplete(s32 id) {
    if (id == 0xFF) {
        return 1;
    }
    if (D_801FC818[id] >= 2) {
        return 1;
    }
    if (D_801FC818[AudioLoad_GetRealTableIndex(2, id)] >= 2) {
        return 1;
    }
    return 0;
}
