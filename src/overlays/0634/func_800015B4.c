// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182BE0(s32);                         /* extern */

void func_800015B4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 0xF) {
        func_80182BE0(arg4 + 0x3C);
    }
}
