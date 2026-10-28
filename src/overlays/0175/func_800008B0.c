// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, s16);   /* extern */

void func_800008B0(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (!(temp_v0 & 1) && !((temp_v0 >> 8) & 1)) {
        func_800A8248(arg1, 0, arg0 + 0x24, (s16) (((temp_v0 >> 4) & 0xF) * 0x10));
    }
}
