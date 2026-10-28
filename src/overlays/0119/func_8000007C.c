// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F2470(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void func_8000007C(s32 arg0, M2C_UNK arg1) {
    func_800F2470(arg1, arg0 + 0x144, arg0, arg1);
}
