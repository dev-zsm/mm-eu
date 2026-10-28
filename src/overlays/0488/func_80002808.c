// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182B28(M2C_UNK *, s32, s32);         /* extern */
extern M2C_UNK D_80B28008;
extern M2C_UNK D_80B28014;

void func_80002808(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 0xB) {
        func_80182B28(&D_80B28008, arg4 + 0x2A8, arg1);
    }
    if (arg1 == 0x10) {
        func_80182B28(&D_80B28014, arg4 + 0x2C0, arg1);
    }
}
