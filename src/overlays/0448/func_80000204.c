// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_80000204(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) != 1) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0xFD);
    }
}
