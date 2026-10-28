// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8012C098();                                /* extern */
M2C_UNK func_80B4B7D0(s32);                         /* extern */

void func_80000158(s32 arg0) {
    if (func_8012C098() != 0) {
        func_80B4B7D0(arg0);
    }
}
