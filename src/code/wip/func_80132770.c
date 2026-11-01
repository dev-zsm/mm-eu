#include "types.h"

extern u8 D_801E7DE8[];
/* The ROM keeps the script pointer in v1, the return value 0 in v0 and the flag in a0; we do not (17 instructions differ). */

s32 Schedule_CheckWeekEventRegS(s32 a0, u8 **script, s32 a2) {
    u8 *cmd = *script;
    s32 ret = 0;
    u16 flag = (cmd[1] << 8) | cmd[2];

    if ((D_801E7DE8[flag >> 8] & flag) & 0xFF) {
        *script = cmd + (s8)cmd[3];
    }
    return ret;
}
