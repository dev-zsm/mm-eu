// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80AB45E8(s32);                             /* extern */
M2C_UNK func_80AB470C(s32);                         /* extern */

void func_80000228(s32 arg0) {
    if (func_80AB45E8(arg0) != 0) {
        func_80AB470C(arg0);
    }
}
