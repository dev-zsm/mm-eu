// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80181278(s32);                         /* extern */

void func_80004A6C(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 4) {
        func_80181278(arg4 + 0x36C);
    }
}
