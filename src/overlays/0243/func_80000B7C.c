// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80980404;

void func_80000B7C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x11C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80980404;
}
