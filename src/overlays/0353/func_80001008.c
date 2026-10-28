// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A47590;

void func_80001008(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3A8) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80A47590;
}
