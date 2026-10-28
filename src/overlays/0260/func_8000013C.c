// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, M2C_UNK, s32, s16);      /* extern */

void func_8000013C(s32 arg0, s16 arg1, s32 arg2) {
    if (!(arg1 & 0x10)) {
        func_800A8248(arg2, 0, arg0, (s16) (arg1 * 0x10));
    }
}
