#include "types.h"

extern s32 Flags_GetSwitch(void *, s32);

s32 MsgEvent_CheckSwitchFlag(void *actor, void *play, u8 **script, void *arg3) {
    u8 *cmd = *script;
    // low byte first in the OR: operand order needed to match register allocation
    s16 flag = cmd[2] | (cmd[1] << 8);
    s16 skip = cmd[4] | (cmd[3] << 8);

    if (Flags_GetSwitch(play, flag)) {
        *script += skip;
    }
    return 0;
}
