// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8098A534;

void func_800009D8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_8098A534;
    M2C_FIELD(arg0, s32 *, 0x24C) = 4;
}
