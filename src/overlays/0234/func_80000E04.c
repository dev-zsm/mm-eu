// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809729A0;

void func_80000E04(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1AC) = 0x2EE0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809729A0;
}
