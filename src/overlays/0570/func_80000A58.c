// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800EDCC4(s32, s32, s32);               /* extern */
s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_80BB6880(s32, s32);                        /* extern */

void func_80000A58(s32 arg0, s32 arg1) {
    if (func_80BB6880(arg0, arg1) != 0) {
        func_800EDCC4(arg0, arg1, func_800EDFA0(arg1, 0x1F8));
    }
}
