#include "types.h"

extern u8 D_801C2D38[];
extern u8 D_801E6F60[];

s32 MsgEvent_CheckItem(s32 arg0, s32 arg1, u8 **script, s32 arg3) {
    u8 *cmd = *script;
    u16 item = (cmd[1] << 8) | cmd[2];
    s16 offset = (cmd[3] << 8) | cmd[4];

    if (item == D_801E6F60[D_801C2D38[item]]) {
        *script = cmd + offset;
    }
    return 0;
}
