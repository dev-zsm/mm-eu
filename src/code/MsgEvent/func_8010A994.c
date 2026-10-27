#include "types.h"

s32 MsgEvent_CheckCallback(void *play, void *arg1, u8 **cmdPtr, s32 (*callback)(void *, void *, u8 **)) {
    u8 *cmd = *cmdPtr;
    s16 offset = cmd[2] | (cmd[1] << 8);

    if (callback == NULL || callback(play, arg1, cmdPtr) != 0) {
        // The (s32) cast only flips the operand order of the addu.
        *cmdPtr = (u8 *)((s32)*cmdPtr + offset);
    } else {
        return 1;
    }
    return 0;
}
