#include "types.h"

extern s16 D_801E6F2A;

// Remaining diff: the ROM keeps the two s16 values in a0/a1 (never v0); we get v0/a0.
s32 MsgEvent_CheckRupees(s32 arg0, s32 arg1, u8 **script, s32 arg3) {
    s16 limit = ((*script)[1] << 8) | (*script)[2];
    s16 offset = ((*script)[3] << 8) | (*script)[4];

    if (limit <= D_801E6F2A) {
        *script += offset;
    }
    return 0;
}
