// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(s32);                             /* extern */
M2C_UNK func_80BED5C8(s32);                         /* extern */

void func_80000158(s32 arg0) {
    if (func_800B8400(arg0) != 0) {
        func_80BED5C8(arg0);
    }
}
