// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6730(s32);                         /* extern */
M2C_UNK func_80A796B0(s32);                         /* extern */

void func_80000034(s32 arg0) {
    func_80A796B0(arg0);
    func_800B6730(arg0);
}
