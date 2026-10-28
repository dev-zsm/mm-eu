// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B89D4(s32, s32);                    /* extern */
s32 func_80B08B00(s32, s32);                        /* extern */

void func_800000F0(s32 arg0, s32 arg1) {
    if (func_80B08B00(arg0, arg1) == 0) {
        func_800B89D4(arg0, arg1);
    }
}
