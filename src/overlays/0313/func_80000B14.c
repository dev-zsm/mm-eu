// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A14610;

void func_80000B14(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x14C) = 8;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A14610;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
