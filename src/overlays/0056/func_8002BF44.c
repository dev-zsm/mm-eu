// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808352A8(u8 *, s16, M2C_UNK, u8 *); /* extern */

void func_8002BF44(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    M2C_FIELD(arg1, f32 *, 0xAD0) = 2.5f;
    func_808352A8(arg1 + 0x24, M2C_FIELD(arg1, s16 *, 0xBE), 0x43340000, arg1 + 0x3A0);
}
