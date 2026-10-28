// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B647BC;

void func_80000354(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5C8) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x5B8) = &D_80B647BC;
}
