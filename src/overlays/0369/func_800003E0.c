// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A69D68;
extern M2C_UNK D_80A69F84;

void func_800003E0(u8 *arg0) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A69F84;
    M2C_FIELD(arg0, f32 *, 0x16C) = (f32) (temp_f0 - 90.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A69D68;
    M2C_FIELD(arg0, f32 *, 0x168) = temp_f0;
}
