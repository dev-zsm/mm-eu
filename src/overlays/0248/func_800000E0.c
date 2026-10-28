// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5BA4(s32, s32);                    /* extern */
s32 func_80984780(u8 *, s32);                     /* extern */

void func_800000E0(u8 *arg0, s32 arg1) {
    if (func_80984780(arg0, arg1) != 0) {
        func_800B5BA4(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F);
    }
}
