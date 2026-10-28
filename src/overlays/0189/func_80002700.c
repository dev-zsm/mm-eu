// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_801C9EE0;

void func_80002700(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 4) {
        func_80182B28(&D_801C9EE0, arg4 + 0x1BC);
    }
}
