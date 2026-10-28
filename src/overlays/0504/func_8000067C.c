// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B54370;

void func_8000067C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x23A) = 0xD;
    M2C_FIELD(arg0, s16 *, 0x23C) = 0;
    M2C_FIELD(arg0, s16 *, 0x23E) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_80B54370;
}
