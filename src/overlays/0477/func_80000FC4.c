// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B15828;

void func_80000FC4(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x3C1) = 0x50;
    M2C_FIELD(arg0, s8 *, 0x3C6) = 0;
    M2C_FIELD(arg0, s8 *, 0x3C7) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x3C8) = &D_80B15828;
}
