// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001B30(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 8);
    if (M2C_FIELD(arg1, s8 *, 0x147) == 0x12) {
        M2C_FIELD(arg1, s16 *, 0xB28) = -2;
    } else {
        M2C_FIELD(arg1, s16 *, 0xB28) = -1;
    }
    M2C_FIELD(arg1, s16 *, 0xACC) = 0;
}
