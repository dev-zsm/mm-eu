// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80929298();                            /* extern */
M2C_UNK func_80929308(u8 *, s32);                 /* extern */

void func_80000E8C(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x254);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x254) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x254);
    }
    if (var_v1 == 0) {
        func_80929298();
    }
    func_80929308(arg0, arg1);
}
