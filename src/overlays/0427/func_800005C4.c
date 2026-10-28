// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */

void func_800005C4(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1AD);
    if ((s32) temp_v0 >= 9) {
        M2C_FIELD(arg0, u8 *, 0x1AD) = (u8) (temp_v0 - 8);
    } else {
        M2C_FIELD(arg0, u8 *, 0x1AD) = 0U;
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x1AC) = (s8) (M2C_FIELD(arg0, s8 *, 0x1AC) - 1);
    if (M2C_FIELD(arg0, s8 *, 0x1AC) <= 0) {
        func_800B6490();
    }
}
