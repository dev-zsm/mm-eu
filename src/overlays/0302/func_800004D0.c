// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80A050A8(u8 *);                      /* extern */

void func_800004D0(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x29C);
    if (temp_v0 >= 0xB) {
        func_800B8C4C(M2C_FIELD(arg0, s32 *, 0x120), 0x383C, arg0);
        M2C_FIELD(arg0, s16 *, 0x29C) = 0;
        func_80A050A8(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x29C) = (s16) (temp_v0 + 1);
}
