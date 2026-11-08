// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_80969F28;

void func_8000189C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x171) &= ~1;
    M2C_FIELD(arg0, u8 *, 0x172) &= ~1;
    if ((M2C_FIELD(arg0, s32 *, 4) & 0x2000) == 0x2000) {
        M2C_FIELD(arg0, s32 *, 4) &= ~0x2000;
    }
    M2C_FIELD(arg0, u8 **, 0x144) = &D_80969F28;
}
