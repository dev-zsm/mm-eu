// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80B16970(s32, s32);                    /* extern */

void func_800015E0(s32 arg0, s32 arg1) {
    func_80B16970(arg0, arg1);
    if (func_800EE03C(arg1, 0x1C9) != 0) {
        func_800B6490(arg0);
    }
}
