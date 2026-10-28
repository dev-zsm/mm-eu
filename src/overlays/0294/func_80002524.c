// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, s32);                    /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */

s32 func_80002524(s32 arg0, s16 arg1) {
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
        goto block_4;
    }
    if (func_800F1984(arg1) != 0) {
        func_800F1A08(arg1, arg0);
        return 1;
    }
block_4:
    func_800F1944(arg1);
    return 0;
}
