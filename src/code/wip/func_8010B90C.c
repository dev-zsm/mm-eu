#include "types.h"

extern s32 D_801E6F08;

s32 MsgEvent_CheckOnDay(s32 arg0, s32 arg1, u8 **script, s32 arg3) {
    u8 *cmd = *script;
    s16 day = (cmd[1] << 8) | cmd[2];
    s16 offset = (cmd[3] << 8) | cmd[4];

    if (day == D_801E6F08) {
        *script = cmd + offset;
    }
    return 0;
}
