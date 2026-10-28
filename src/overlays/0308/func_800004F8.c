// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80A10E80(u8 *);                      /* extern */

void func_800004F8(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1DA);
    if (temp_v0 >= 0x15) {
        func_800B8C4C(M2C_FIELD(arg0, s32 *, 0x120), 0x3880, arg0);
        M2C_FIELD(arg0, s16 *, 0x1DA) = 0;
        func_80A10E80(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1DA) = (s16) (temp_v0 + 1);
}
