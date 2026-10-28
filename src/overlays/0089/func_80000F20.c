// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(s32, M2C_UNK);                /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808ACFA8(s32);                         /* extern */

void func_80000F20(s32 arg0, M2C_UNK arg1) {
    func_800B8D94(arg0, 0x31D7);
    if (func_80137070(arg0 + 0x144) != 0) {
        func_808ACFA8(arg0);
    }
}
