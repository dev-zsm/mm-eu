// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8098A220;

void func_800006B4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_8098A220;
    M2C_FIELD(arg0, s32 *, 0x24C) = 4;
    M2C_FIELD(arg0, s16 *, 0x268) = 0;
    M2C_FIELD(arg0, s16 *, 0x26A) = 0;
    M2C_FIELD(arg0, s16 *, 0x26C) = 0;
    M2C_FIELD(arg0, s16 *, 0x266) = 0;
}
