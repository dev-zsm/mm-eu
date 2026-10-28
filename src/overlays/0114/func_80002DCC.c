// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E1F64(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void func_80002DCC(s32 arg0, M2C_UNK arg1) {
    func_800E1F64(arg1, arg0 + 0x18C, arg0, arg1);
}
