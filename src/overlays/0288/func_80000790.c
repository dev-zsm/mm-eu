// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */

void func_80000790(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if ((temp_v0 == 2) || (temp_v0 == 0) || (temp_v0 == 1)) {
        func_800C625C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg0);
    }
}
