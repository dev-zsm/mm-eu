// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_800F0308(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
s32 func_8089ED80(s32, s32);                        /* extern */

void func_80000E70(s32 arg0, s32 arg1) {
    if (func_8089ED80(arg0, arg1) >= 0) {
        func_800F0308(arg1, arg0 + 0x24, 0x3C, 0x3949);
        func_800B6490(arg0);
    }
}
