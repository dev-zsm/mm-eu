// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8098A6A0(s32, s32);                    /* extern */
M2C_UNK func_8098A77C(s32, s32);                    /* extern */

void func_80000D50(s32 arg0, s32 arg1) {
    func_8098A6A0(arg0, arg1);
    func_8098A77C(arg0, arg1);
}
