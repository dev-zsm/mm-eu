// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80969190;

void func_80000B20(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x28;
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x30) = 0;
    M2C_FIELD(arg0, u8 *, 0x171) = (u8) (M2C_FIELD(arg0, u8 *, 0x171) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80969190;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
