// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8083A914(s32, s32, s32);               /* extern */

void func_8002BFC4(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_8083A914(arg1, arg0, arg1);
}
