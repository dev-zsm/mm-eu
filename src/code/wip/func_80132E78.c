#include "types.h"

extern s16 D_801E6F0A;

s32 Schedule_CheckNotInDayS(s32 arg0, u8 **script, s32 arg2) {
    u8 *cmd = *script;
    s16 day = (cmd[1] << 8) | cmd[2];

    if (day != D_801E6F0A) {
        *script = cmd + (s8)cmd[3];
    }
    return 0;
}
