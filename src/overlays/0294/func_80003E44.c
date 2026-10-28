// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809F9BA4;

void func_80003E44(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x19C);
    if ((M2C_FIELD(arg0, u16 *, 0x390) & 0x1000) && (((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s16 *, 0) == 0x1AF) && (M2C_FIELD(temp_v0, s16 *, 0x1C) & 1)) || (M2C_FIELD(arg0, u8 *, 0xB9) == 2))) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F9BA4;
    }
}
