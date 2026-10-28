// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B0BEB8;

void func_80000EAC(u8 *arg0) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) | 8);
    M2C_FIELD(arg0, s16 *, 0x28C) = 1;
    M2C_FIELD(arg0, s16 *, 0x290) = 0;
    M2C_FIELD(arg0, s16 *, 0x284) = 0;
    M2C_FIELD(arg0, s16 *, 0x286) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B0BEB8;
}
