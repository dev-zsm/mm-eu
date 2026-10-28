// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80ABC678;

void func_80000B5C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x29E) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80ABC678;
}
