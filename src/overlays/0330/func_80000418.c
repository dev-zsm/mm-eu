// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A2868C;

void func_80000418(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x14C) = 0x64;
    M2C_FIELD(arg0, u8 *, 0x195) = (u8) (M2C_FIELD(arg0, u8 *, 0x195) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A2868C;
    M2C_FIELD(arg0, f32 *, 0x70) = 3.5f;
}
