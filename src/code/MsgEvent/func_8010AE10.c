// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Flags_GetCollectible(s32, s32);
s32 Flags_SetCollectible(s32, s32);

s32 MsgEvent_SetCollectible(u8 *arg0, s32 arg1, u8 **arg2, s32 arg3) {
    s32 sp18;
    s32 temp_a1;
    u8 *temp_v0;
    

    temp_v0 = *arg2;
    temp_a1 = temp_v0[2] | (temp_v0[1] << 8);
    sp18 = temp_a1;
    if (Flags_GetCollectible(arg1, temp_a1) == 0) {
        Flags_SetCollectible(arg1, temp_a1);
    }
    *(s32 *)(arg0 + 0x120) = 0;
    return 0;
}
