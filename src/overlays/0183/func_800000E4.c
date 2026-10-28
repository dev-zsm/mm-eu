// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_8094C538;

void func_800000E4(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2FA);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2FA) = (s16) (temp_v0 - 1);
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x2F8);
    if (temp_v0_2 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2F8) = (s16) (temp_v0_2 - 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2F4) = &D_8094C538;
    M2C_FIELD(arg0, s16 *, 0x2FA) = func_800FF250(0xA, 0xA, arg0);
}
