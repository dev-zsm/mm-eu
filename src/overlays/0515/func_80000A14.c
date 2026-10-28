// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B67B00;

void func_80000A14(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x17D) = 0x14;
    M2C_FIELD(arg0, M2C_UNK **, 0x168) = &D_80B67B00;
}
