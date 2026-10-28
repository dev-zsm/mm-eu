// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8);                          /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_8013DD10(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

s32 func_80000250(u8 *arg0, u8 *arg1) {
    s32 temp_v0;
    u8 *var_v0;

    var_v0 = M2C_FIELD(arg0, u8 **, 0xD78);
    if (M2C_FIELD(var_v0, u16 *, 2) == 0x145F) {
        temp_v0 = func_8013DD10(arg1, 0, 1, 0x25C);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, s32 *, 0x730) = temp_v0;
        }
        var_v0 = M2C_FIELD(arg0, u8 **, 0xD78);
    }
    if (M2C_FIELD(var_v0, u8 *, 1) != 0) {
        func_800F1D6C(0x7C);
        func_800F1944(M2C_FIELD(arg0, s8 *, 0xD8D));
        M2C_FIELD(arg1, s8 *, 0x1682E) = 0x44;
    }
    return 0;
}
