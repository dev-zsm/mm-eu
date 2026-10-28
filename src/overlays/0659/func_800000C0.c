// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80C0873C;

void func_800000C0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x258) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80C0873C;
}
