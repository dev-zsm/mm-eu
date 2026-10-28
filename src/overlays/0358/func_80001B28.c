// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(M2C_UNK, s32, M2C_UNK);       /* extern */
M2C_UNK func_80A4D8CC(s32);                         /* extern */

void func_80001B28(s32 arg0, M2C_UNK arg1) {
    func_800E09D8(arg1, arg0 + 0x2A8, arg1);
    func_80A4D8CC(arg0);
}
