// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8083A064;

void func_8000D29C(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    M2C_FIELD(arg1, M2C_UNK **, 0x138) = &D_8083A064;
    M2C_FIELD(arg1, s32 *, 0x13C) = 0;
    temp_v0 = M2C_FIELD(arg0, s16 *, 0xA4);
    if (temp_v0 == 0x2D) {
        M2C_FIELD(arg1, s16 *, 0x48) = 0xBD8;
        M2C_FIELD(arg1, s16 *, 0x4A) = -0x4D74;
        M2C_FIELD(arg1, s16 *, 0xAE8) = 0x14;
    } else if (temp_v0 == 0xD) {
        M2C_FIELD(arg1, s16 *, 0x48) = 0x9A6;
        M2C_FIELD(arg1, s16 *, 0x4A) = 0x2102;
        M2C_FIELD(arg1, s16 *, 0xAE8) = 2;
    } else {
        M2C_FIELD(arg1, s16 *, 0x48) = 0x9A6;
        M2C_FIELD(arg1, s16 *, 0x4A) = 0x2102;
        M2C_FIELD(arg1, s16 *, 0xAE8) = 0x14;
    }
    M2C_FIELD(arg0, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg0, u8 *, 0x1CA5) | 2);
}
