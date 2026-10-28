// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FED2C(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */

void func_80000250(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    s16 temp_v0;

    if (M2C_FIELD(arg2, s16 *, 0x5C) < 0xA) {
        func_800FED2C(arg2 + 0x40, 0, 0xA, arg2);
        return;
    }
    temp_v0 = M2C_FIELD(arg2, s16 *, 0x40);
    if (temp_v0 < 0x64) {
        M2C_FIELD(arg2, s16 *, 0x40) = (s16) (temp_v0 + 0xA);
    }
}
