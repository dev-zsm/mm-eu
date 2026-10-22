// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80151DF4(s32, s32, s32, void *);

s32 MsgEvent_BeginText(s32 arg0, s32 arg1, u8 **arg2, s32 arg3) {
    u8 *temp_v0;

    temp_v0 = *arg2;
    func_80151DF4(arg1, (temp_v0[2] | (temp_v0[1] << 8)) & 0xFFFF, 0, arg2);
    return 0;
}
