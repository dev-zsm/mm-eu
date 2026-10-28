// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018453C(s32, s32);                    /* extern */

void func_800000B8(s32 arg0, M2C_UNK arg1) {
    func_8018453C(arg0 + 0x144, arg0);
}
