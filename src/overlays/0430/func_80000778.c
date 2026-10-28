// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_800B8400(s32, s32);                        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_80000778(s32 arg0, s32 arg1) {
    if (func_800B8400(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0x107D, 0);
        func_800B6490(arg0);
    }
}
