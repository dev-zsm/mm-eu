// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7D4C(s32, s32);                    /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_80A48C58;

void func_80002384(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    func_800E7D4C(arg1, arg4 + 0x190);
    if (arg1 == 0x16) {
        func_80182B28(&D_80A48C58, arg4 + 0x3C);
    }
}
