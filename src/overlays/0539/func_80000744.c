// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5BA4(s32, M2C_UNK);                /* extern */

void func_80000744(u8 *arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    M2C_FIELD(arg0, s8 *, 0x15D) = arg2;
    M2C_FIELD(arg0, s8 *, 0x15E) = 0x50;
    func_800B5BA4(arg1, arg3);
}
