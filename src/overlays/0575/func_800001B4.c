// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80BBA430(s32);                             /* extern */
M2C_UNK func_80BBA618(s32);                         /* extern */

void func_800001B4(s32 arg0) {
    if (func_80BBA430(arg0) != 0) {
        func_80BBA618(arg0);
    }
}
