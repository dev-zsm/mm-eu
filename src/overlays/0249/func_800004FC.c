// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80984E38(s32, s32);                    /* extern */
M2C_UNK func_80984F4C(s32, s32);                    /* extern */
s32 func_80984F8C(s32);                             /* extern */

void func_800004FC(s32 arg0, s32 arg1) {
    func_80137070(arg0 + 0x194);
    func_80984E38(arg0, arg1);
    if (func_80984F8C(arg0) != 0) {
        func_80984F4C(arg0, arg1);
    }
}
