// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A98FCC;

void func_80001458(u8 *arg0, M2C_UNK arg1) {
    s32 temp_hi;

    temp_hi = (s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5;
    if (((temp_hi == 3) && ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0x4000)) || (temp_hi >= 4) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) & 0x40)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A98FCC;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
}
