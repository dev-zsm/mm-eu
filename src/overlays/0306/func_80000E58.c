// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A0D0D0;

void func_80000E58(u8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), s16 *, 0x1C) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0D0D0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
