#include "types.h"

extern void func_801520F8(s32 arg0, u8 arg1);

s32 MsgEvent_NotebookEvent(s32 arg0, s32 arg1, u8 **arg2, s32 arg3) {
    u8 *cmd = *arg2;
    s32 value;

    value = cmd[2] | (cmd[1] << 8);
    func_801520F8(arg1, value);
    return 0;
}
