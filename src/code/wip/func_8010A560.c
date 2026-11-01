#include "types.h"

extern u8 D_801E7DE8[];

s32 MsgEvent_CheckWeekEventReg(void *msgCtx, void *play, u8 **cmdPtr, void *arg3) {
    s32 ret = 0;
    u8 *cmd = *cmdPtr;
    s32 flag = ((cmd[1] << 8) | cmd[2]) & 0xFFFF;
    s16 skip = (cmd[3] << 8) | cmd[4];

    if (D_801E7DE8[flag >> 8] & flag & 0xFF) {
        *cmdPtr = cmd + skip;
    }
    return ret;
}
