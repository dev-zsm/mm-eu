// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80C080A4;

void func_800000B8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x27C) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80C080A4;
}
