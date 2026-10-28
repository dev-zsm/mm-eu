// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800CAD00(s32);                             /* extern */
M2C_UNK func_8091BA14(s32);                         /* extern */
M2C_UNK func_8091D364(s32);                         /* extern */

void func_80001B44(s32 arg0, M2C_UNK arg1) {
    if (func_800CAD00(arg0) != 0) {
        func_8091D364(arg0);
    }
    func_8091BA14(arg0);
}
