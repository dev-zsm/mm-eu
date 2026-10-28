// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(s32, M2C_UNK, M2C_UNK, s32);  /* extern */

s32 func_800004C8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_8013B284(arg0 + 0x208, 3, 7, arg0);
    return 1;
}
