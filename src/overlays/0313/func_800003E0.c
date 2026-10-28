// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A13ED4;

void func_800003E0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x14C) = 0x19;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A13ED4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
