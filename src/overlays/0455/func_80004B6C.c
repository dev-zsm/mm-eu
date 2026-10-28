// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AEEB50;

void func_80004B6C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1A8) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEEB50;
    M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
}
