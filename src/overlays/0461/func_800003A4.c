// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(s32);                             /* extern */
M2C_UNK func_80AF917C(s32);                         /* extern */

void func_800003A4(s32 arg0) {
    if (func_800B8400(arg0) != 0) {
        func_80AF917C(arg0);
    }
}
