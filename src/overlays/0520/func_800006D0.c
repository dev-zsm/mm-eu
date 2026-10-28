// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B73658(s32, s32);                    /* extern */
s32 func_80B737DC(s32, s32);                        /* extern */

void func_800006D0(s32 arg0, s32 arg1) {
    if (func_80B737DC(arg0, arg1) == 2) {
        func_80B73658(arg0, arg1);
    }
}
