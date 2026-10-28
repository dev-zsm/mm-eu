// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A7C50(s32, u8 *, M2C_UNK);        /* extern */
s32 func_800B5CDC(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_80000018(u8 *arg0, s32 arg1) {
    if (func_800B5CDC(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F0) >> 4) != 0) {
        func_800A7C50(arg1, arg0 + 0x24, 2);
        func_800B6490(arg0);
    }
}
