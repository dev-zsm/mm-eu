// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013DD78(s32, s32, s32, M2C_UNK);      /* extern */

void func_80000050(s32 arg0, s32 arg1) {
    func_8013DD78(arg1, arg0 + 0x1D8, arg0 + 0x1FE, 0x13);
}
