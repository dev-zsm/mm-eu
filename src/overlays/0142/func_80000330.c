// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, M2C_UNK, s32);  /* extern */

void func_80000330(s32 arg0, M2C_UNK arg1) {
    func_800E0FAC(arg1, arg0 + 0x148, arg1, arg0);
}
