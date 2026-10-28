// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8098A36C;

void func_80000810(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_8098A36C;
    M2C_FIELD(arg0, s32 *, 0x24C) = 5;
}
