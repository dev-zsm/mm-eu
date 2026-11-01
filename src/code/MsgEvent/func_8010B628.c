#include "types.h"

extern void Flags_SetSwitch(s32 a0, s16 a1);

s32 MsgEvent_SetSwitchFlag(s32 a0, s32 a1, u8 **script, s32 a3) {
    u8 *cmd = *script;

    Flags_SetSwitch(a1, cmd[2] | (cmd[1] << 8));
    return 0;
}
