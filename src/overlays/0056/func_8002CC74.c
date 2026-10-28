// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80124764(s32);                             /* extern */
M2C_UNK func_808586B0(s32, s32, s32);               /* extern */
M2C_UNK func_808589F4(s32, s32, M2C_UNK);           /* extern */

void func_8002CC74(s32 arg0, s32 arg1, s32 arg2) {
    if (func_80124764(arg1) != 0) {
        func_808589F4(arg0, arg1, 0);
        return;
    }
    func_808586B0(arg0, arg1, arg2);
}
