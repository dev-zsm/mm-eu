// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7D4C(s32, s32);                    /* extern */

void func_8000378C(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 1) {
        func_800E7D4C(arg1, arg4 + 0x23C);
    }
}
