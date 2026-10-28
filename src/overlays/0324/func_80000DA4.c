// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7D4C(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_80000DA4(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    func_800E7D4C(arg1, arg4 + 0x1DC, arg1);
}
