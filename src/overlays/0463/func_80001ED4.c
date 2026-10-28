// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AFD734;

void func_80001ED4(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x33D) = (u8) (M2C_FIELD(arg0, u8 *, 0x33D) & ~3);
    M2C_FIELD(arg0, u8 *, 0x33E) = (u8) (M2C_FIELD(arg0, u8 *, 0x33E) & ~3);
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFD734;
}
