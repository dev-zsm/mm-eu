// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B24DF8;

void func_80000000(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x17E) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80B24DF8;
}
