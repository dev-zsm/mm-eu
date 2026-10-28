// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80988A78;

void func_8000093C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80988A78;
    M2C_FIELD(arg0, s32 *, 0x160) = 4;
}
