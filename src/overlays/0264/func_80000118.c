// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80991DC4;

void func_80000118(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x154) = 0x113;
    M2C_FIELD(arg0, s16 *, 0x150) = 1;
    M2C_FIELD(arg0, s16 *, 0x15E) = 0x1E;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80991DC4;
}
