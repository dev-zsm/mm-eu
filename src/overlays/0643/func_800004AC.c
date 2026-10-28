// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BFFD34;

void func_800004AC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x186) = (s16) (M2C_FIELD(arg0, s16 *, 0x186) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x186) <= 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BFFD34;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
}
