// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_8000228C(s32 arg0, M2C_UNK arg1) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF38) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF38) | 0x20);
}
