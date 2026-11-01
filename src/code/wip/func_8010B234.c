#include "types.h"

extern u32 D_801C2A08[];
extern u32 D_801E6FAC;

s32 MsgEvent_CheckHasSong(void *arg0, s32 arg1, u8 **cmdPtr, s32 arg3) {
    u8 *cmd = *cmdPtr;
    u16 flagIndex = (cmd[1] << 8) | cmd[2];
    s16 jumpOffset = (cmd[3] << 8) | cmd[4];

    if (D_801C2A08[flagIndex] & D_801E6FAC) {
        *cmdPtr = cmd + jumpOffset;
    }
    return 0;
}
