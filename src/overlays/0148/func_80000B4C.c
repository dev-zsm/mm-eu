// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80913B64;

void func_80000B4C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80913B64;
    M2C_FIELD(arg0, s16 *, 0x222) = 0;
}
