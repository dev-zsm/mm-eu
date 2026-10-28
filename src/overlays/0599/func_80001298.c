// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BCFB74;

void func_80001298(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x254) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x23C) = &D_80BCFB74;
}
