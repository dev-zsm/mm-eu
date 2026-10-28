// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B24F28(s32, s32);                    /* extern */
M2C_UNK func_80B25038(s32, s32);                    /* extern */

void func_80000048(s32 arg0, s32 arg1) {
    func_80B25038(arg0, arg1);
    func_80B24F28(arg0, arg1);
}
