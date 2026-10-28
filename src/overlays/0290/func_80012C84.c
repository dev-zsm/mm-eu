// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809E0CC4(s32, s32);                    /* extern */
M2C_UNK func_809EC470(s32);                         /* extern */

void func_80012C84(s32 arg0, s32 arg1) {
    func_809EC470(arg1);
    func_809E0CC4(arg0, arg1);
}
