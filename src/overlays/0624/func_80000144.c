// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80BECA70();                                /* extern */

void func_80000144(s32 arg0, M2C_UNK arg1) {
    if (func_80BECA70() != 0) {
        func_800B6490(arg0);
    }
}
