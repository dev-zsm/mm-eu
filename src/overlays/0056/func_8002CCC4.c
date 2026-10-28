// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s16);                         /* extern */
s16 func_800F1E2C();                                /* extern */
s32 func_8083C914(s32, u8 *);                     /* extern */
M2C_UNK func_808586B0(u8 *, s32);                 /* extern */

void func_8002CCC4(u8 *arg0, s32 arg1) {
    func_808586B0(arg0, arg1);
    if (func_8083C914(arg1, arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1F2C) = 3;
        func_800F1D6C(func_800F1E2C());
    }
}
