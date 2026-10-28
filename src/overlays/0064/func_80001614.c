// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, s32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_8086E008(u8 *);                      /* extern */

void func_80001614(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
    M2C_FIELD(arg0, s8 *, 0x11C) = 0xA;
    if ((temp_v0 == NULL) || (M2C_FIELD(temp_v0, s32 *, 0x138) == 0)) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x41200000, arg0) != 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
            func_8086E008(arg0);
        }
    }
}
