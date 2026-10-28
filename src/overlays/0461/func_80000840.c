// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F1984(s16, u8 *);                     /* extern */
M2C_UNK func_800F1D6C(s16, u8 *);                 /* extern */

void func_80000840(u8 *arg0, M2C_UNK arg1) {
    s16 temp_a0;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x19A);
    if (temp_v0 < 0x3C) {
        M2C_FIELD(arg0, s16 *, 0x19A) = (s16) (temp_v0 + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, s16 *, 0x196);
    if ((temp_a0 != -1) && (func_800F1984(temp_a0, arg0) == 0)) {
        func_800F1D6C(M2C_FIELD(arg0, s16 *, 0x196), arg0);
    }
}
