// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B48604;
extern M2C_UNK D_80B49B2C;

void func_800022CC(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B49B2C;
    M2C_FIELD(arg0, s16 *, 0x206) = 0xF;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B48604;
}
