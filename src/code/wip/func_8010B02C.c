#include "types.h"

extern u8 D_801E7EFC[];

/* The ROM keeps the script pointer in v1, the return value 0 in v0 and the offset in a0; we do not. */
s32 MsgEvent_CheckEventInf(s32 a0, s32 a1, u8 **script, s32 a3) {
    u8 *cmd = *script;
    s32 ret = 0;
    s16 offset = (cmd[3] << 8) | cmd[4];

    if (D_801E7EFC[cmd[1]] & cmd[2]) {
        *script = cmd + offset;
    }
    return ret;
}
