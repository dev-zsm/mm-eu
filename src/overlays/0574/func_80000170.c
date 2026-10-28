// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E2318(s32, s32, s32, s32);          /* extern */

void func_80000170(s32 arg0, s32 arg1) {
    func_800E2318(arg1, arg1 + 0x18884, arg0 + 0x144, arg1);
}
