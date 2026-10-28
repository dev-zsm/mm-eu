// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(M2C_UNK, s32, M2C_UNK, s32);  /* extern */

void func_8000141C(s32 arg0, M2C_UNK arg1) {
    func_800E09D8(arg1, arg0 + 0x144, arg1, arg0);
}
