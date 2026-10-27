// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Room_Init(s32 arg0, u8 *arg1) {
    s32 var_v0;
    u8 *var_v1;

    *(s8 *)arg1 = -1;
    *(s32 *)(arg1 + 0xC) = 0;
    arg1[0x78] = 1;
    arg1[0x79] = 0;
    var_v0 = 0;
    var_v1 = arg1;
    do {
        var_v0 += 1;
        var_v1 += 2;
        *(s16 *)(var_v1 + 0x78) = 0;
    } while (var_v0 != 3);
}
