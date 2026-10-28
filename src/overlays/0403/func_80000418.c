// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000418(u8 *arg0, s32 arg1) {
    if (arg1 == 1) {
        M2C_FIELD(arg0, u8 *, 8) = 1U;
    } else {
        M2C_FIELD(arg0, u8 *, 8) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 8) != 0) {
        M2C_FIELD(arg0, s16 *, 0xE) = 0x14D;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xE) = 0x264;
}
