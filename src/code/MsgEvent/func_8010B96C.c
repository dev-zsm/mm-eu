#include "types.h"

s32 MsgEvent_CheckCallbackContinue(s32 a0, s32 a1, u8 **cmdPtr, s32 (*callback)(s32, s32)) {
    u8 *cmd = *cmdPtr;
    s16 offset = cmd[2] | (cmd[1] << 8);

    if (callback != NULL) {
        if (callback(a0, a1) != 0) {
            *cmdPtr += offset;
        }
    }
    return 0;
}
