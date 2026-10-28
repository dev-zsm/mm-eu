// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80972BE0;

void func_80001018(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x1B4) = 0x64;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80972BE0;
    M2C_FIELD(arg0, f32 *, 0x78) = -20.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.5f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
