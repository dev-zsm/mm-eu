// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254();                                /* extern */
M2C_UNK func_80A571E4(s32, s32);                    /* extern */
M2C_UNK func_80A57258(s32, s32);                    /* extern */

void func_80001330(s32 arg0, s32 arg1) {
    if (func_800B8254() != 0) {
        func_80A57258(arg0, arg1);
        return;
    }
    func_80A571E4(arg0, arg1);
}
