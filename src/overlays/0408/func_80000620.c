// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B849C(s32, s32);                        /* extern */
M2C_UNK func_800B8588(s32, s32, M2C_UNK);           /* extern */
s32 func_800CAD00(s32);                             /* extern */
M2C_UNK func_80152978(s32, M2C_UNK);                /* extern */
M2C_UNK func_80AAE878(s32);                         /* extern */

void func_80000620(s32 arg0, s32 arg1) {
    if (func_800B849C(arg0, arg1) != 0) {
        func_80152978(arg1, 1);
        func_80AAE878(arg0);
        return;
    }
    if (func_800CAD00(arg0) != 0) {
        func_800B8588(arg0, arg1, 0x42200000);
    }
}
