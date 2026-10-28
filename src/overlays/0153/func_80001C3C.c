// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8091D448;
extern M2C_UNK D_8091D8F0;

void func_80001C3C(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8091D8F0;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8091D448;
}
