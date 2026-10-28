// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */

void func_800001B8(s32 arg0, s32 arg1) {
    func_800E0FAC(arg1, arg0 + 0x144);
    func_800E09D8(arg1, arg0 + 0x190);
}
