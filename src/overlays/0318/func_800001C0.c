// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B246C(s32, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */

void func_800001C0(s32 arg0, s32 arg1) {
    func_800B246C(arg1, arg0 + 8, 0, 0, 0, 0x320);
}
