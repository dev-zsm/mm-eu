// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80B08A80(s32);                             /* extern */

s32 func_80000080(s32 arg0) {
    if (func_80B08A80(arg0) != 0) {
        func_800B6490(arg0);
        return 1;
    }
    return 0;
}
