// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(s32, s32);                    /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_80BB8CA0;

void func_80001078(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 7) {
        func_80182B28(&D_80BB8CA0, arg4 + 0x3C);
        func_800FF32C(arg4 + 0x48, arg4 + 0x30);
    }
}
