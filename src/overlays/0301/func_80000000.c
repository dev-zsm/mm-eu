// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A041A0;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(arg0, s8 *, 0x180) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A041A0;
    M2C_FIELD(arg0, f32 *, 0x158) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x40) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x148) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x15C) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) M2C_FIELD(arg0, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 0x2C);
}
