// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(s32, M2C_UNK);                    /* extern */
M2C_UNK func_800B8364(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_801520F8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80B2A33C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80B2FAE8(s32);                         /* extern */

void func_800075E4(s32 arg0, M2C_UNK arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80B2A33C(arg0, arg1, 0x3334);
        func_801520F8(arg1, 0x1E);
        func_801520F8(arg1, 0x1D);
        func_801520F8(arg1, 5);
        func_80B2FAE8(arg0);
        return;
    }
    func_800B8364(arg0, arg1, 0x44FA0000, -1);
}
