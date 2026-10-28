// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80893230(s32);                             /* extern */
M2C_UNK func_80893B34(s32);                         /* extern */

void func_80000DC4(s32 arg0, M2C_UNK arg1) {
    if (func_80893230(arg0) != 0) {
        func_80893B34(arg0);
    }
}
