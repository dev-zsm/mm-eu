// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80879C68;

void func_80000E1C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x30) = 0x7000;
    M2C_FIELD(arg0, s16 *, 0x190) = 0x12;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80879C68;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 2.5f;
}
