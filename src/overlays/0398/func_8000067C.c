// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA665C;

void func_8000067C(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s16 *, 0) == 0x1A4)) {
        M2C_FIELD(temp_v0, s16 *, 0x338) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x338) + 1);
    }
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AA665C;
}
