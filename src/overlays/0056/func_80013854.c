// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80122E9C;

void func_80013854(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, M2C_UNK **, 0x138) = &D_80122E9C;
    M2C_FIELD(arg1, s32 *, 0x13C) = 0;
}
