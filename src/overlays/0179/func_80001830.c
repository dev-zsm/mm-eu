// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80947A3C;

void func_80001830(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x548) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80947A3C;
}
