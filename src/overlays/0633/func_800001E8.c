// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void func_800001E8(s32 arg0, M2C_UNK arg1) {
    func_800E09D8(arg1, arg0 + 0x270, arg0, arg1);
}
