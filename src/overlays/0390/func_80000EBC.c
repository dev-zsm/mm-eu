// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_80137C58(s32, M2C_UNK);                    /* extern */

void func_80000EBC(s32 arg0) {
    if (func_80137C58(arg0 + 0x148, 0x3F800000) != 0) {
        func_800B8C4C(arg0, 0x2900);
        func_800B8C4C(arg0, 0x2902);
    }
}
