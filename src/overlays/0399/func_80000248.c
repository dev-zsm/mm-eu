// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA6ED0;

void func_80000248(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1A4);
    if (temp_v0 < 0) {
        M2C_FIELD(arg0, s16 *, 0x1A4) = (s16) (temp_v0 + 0x100);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1A4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80AA6ED0;
    M2C_FIELD(arg0, u8 *, 0x1F4) = (u8) (M2C_FIELD(arg0, u8 *, 0x1F4) & 0xFFFE);
}
