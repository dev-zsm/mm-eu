// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809EA338;

void func_80010C60(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809EA338;
    M2C_FIELD(arg0, s16 *, 0x150) = 0x32;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
