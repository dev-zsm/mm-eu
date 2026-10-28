// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, s16);   /* extern */

void func_8000006C(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (!((temp_v0 >> 4) & 1) && (M2C_FIELD(arg0, s16 *, 0x18) != 2)) {
        func_800A8248(arg1, 0, arg0 + 0x24, (s16) ((temp_v0 & 0xF) * 0x10));
    }
}
