// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082E34C(s32, s32, s32);               /* extern */
M2C_UNK func_8083610C(s32, s32);                    /* extern */

void func_80009008(s32 arg0, s32 arg1, s32 arg2) {
    func_8083610C(arg0, arg2);
    func_8082E34C(arg2, arg0, arg1);
}
