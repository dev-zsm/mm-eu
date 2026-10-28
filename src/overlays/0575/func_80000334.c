// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80BBA430(s32);                             /* extern */
M2C_UNK func_80BBA798(s32);                         /* extern */

void func_80000334(s32 arg0) {
    if (func_80BBA430(arg0) == 0) {
        func_80BBA798(arg0);
    }
}
