// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B1E9CC;

void func_80000E58(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x1AD) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80B1E9CC;
}
