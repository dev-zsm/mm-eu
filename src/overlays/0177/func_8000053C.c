// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80944C38;

void func_8000053C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1B6) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80944C38;
}
