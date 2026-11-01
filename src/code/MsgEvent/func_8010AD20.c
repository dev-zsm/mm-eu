#include "types.h"
extern void func_80151E7C(s32 arg0, u16 arg1);

s32 MsgEvent_ContinueText(s32 arg0, s32 arg1, u8 **cmd, s32 arg3) {
    u8 *c = *cmd;
    func_80151E7C(arg1, c[2] | (c[1] << 8));
    return 0;
}
