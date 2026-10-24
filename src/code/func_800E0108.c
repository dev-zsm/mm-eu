// FLAGS: -O2 -g0 -mips2
#include "types.h"
void Camera_SetStateFlag(u8 *, s32);
void func_800E0108(u8 *arg0) {
    s16 v = *(s16 *)(arg0 + 0x15E);
    if (v != 0 && v != 0xA && v != 0x14) {
        *(s16 *)(arg0 + 0x15E) = 0x3E7;
        Camera_SetStateFlag(arg0, 0x416);
        return;
    }
    *(s16 *)(arg0 + 0x15E) = 0x29A;
}
