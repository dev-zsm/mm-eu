// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80ABD0B8;

void func_80001594(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x29E) = 0x14;
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80ABD0B8;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
