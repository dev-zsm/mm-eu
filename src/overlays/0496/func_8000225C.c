// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B48584;

void func_8000225C(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B48584;
}
