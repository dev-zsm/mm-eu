// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8097F9CC;

void func_80000128(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x64;
    M2C_FIELD(arg0, u8 *, 0x211) = (u8) (M2C_FIELD(arg0, u8 *, 0x211) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8097F9CC;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
}
