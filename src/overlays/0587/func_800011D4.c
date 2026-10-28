// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(s32, s32);                    /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_80BC68B8;

void func_800011D4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 9) {
        func_80182B28(&D_80BC68B8, arg4 + 0x3C);
        func_800FF32C(arg4 + 0x48, arg4 + 0x30);
    }
}
