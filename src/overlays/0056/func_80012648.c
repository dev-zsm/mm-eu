// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8083F624(s32, s32);                    /* extern */
M2C_UNK func_8083F6E0(s32, s32);                    /* extern */

void func_80012648(s32 arg0, s32 arg1) {
    func_8083F624(arg0, arg1);
    func_8083F6E0(arg0, arg1);
}
