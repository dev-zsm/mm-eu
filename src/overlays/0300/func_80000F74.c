// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A03710;

void func_80000F74(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x4A0) = &D_80A03710;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
