// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018125C();                            /* extern */

s32 func_800004D0(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    if (arg2 == 8) {
        func_8018125C();
    }
    return 1;
}
