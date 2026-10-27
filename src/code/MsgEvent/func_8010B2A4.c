#include "types.h"

extern s32 Player_GetMask(void *);

s32 MsgEvent_CheckWornMask(void *actor, void *play, u8 **script, void *arg3) {
    u8 *cmd = *script;
    // low byte first in the OR: operand order needed to match register allocation
    s32 maskId = cmd[2] | (cmd[1] << 8);
    s16 skip = cmd[4] | (cmd[3] << 8);

    if (Player_GetMask(play) == maskId) {
        *script += skip;
    }
    return 0;
}
