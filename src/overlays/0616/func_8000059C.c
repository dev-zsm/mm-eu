// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BE8894;

void func_8000059C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x308) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x30A) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x2C0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE8894;
}
