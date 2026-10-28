// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808CADA4;

void func_800015F8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x150) = 0x4000;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808CADA4;
    M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
}
