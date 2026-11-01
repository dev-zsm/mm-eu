#include "types.h"

extern u32 D_801C29F0[];
extern u32 D_801E6FAC;

s32 MsgEvent_CheckQuestItem(u16 item, s16 offset, u8 **script, s16 arg3) {
    u32 flags;
    u8 *cmd = *script;

    item = cmd[2] | (cmd[1] << 8);
    flags = D_801E6FAC;
    offset = cmd[4] | (cmd[3] << 8);
    if (D_801C29F0[item] & flags) {
        *script = cmd + offset;
    }
    return 0;
}
