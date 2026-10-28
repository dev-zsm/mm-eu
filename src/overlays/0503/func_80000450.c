// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B539BC;

void func_80000450(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x282) = 0xE;
    M2C_FIELD(arg0, M2C_UNK **, 0x27C) = &D_80B539BC;
}
