// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800CAD00(s32);                             /* extern */
M2C_UNK func_8091BD28(s32);                         /* extern */
M2C_UNK func_8091BD58(s32, s32);                    /* extern */
M2C_UNK func_8091BD98(s32);                         /* extern */
M2C_UNK func_8091D504(s32);                         /* extern */

void func_80001CCC(s32 arg0, s32 arg1) {
    if (func_800CAD00(arg0) == 0) {
        func_8091BD58(arg0, arg1);
        func_8091BD98(arg0);
        func_8091BD28(arg0);
        func_8091D504(arg0);
    }
}
