// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA3F84;

void func_80001578(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg1, u8 *, 0x16C68) == 8) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AA3F84;
        M2C_FIELD(temp_v0, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xA6C) & ~0x20);
    }
}
