// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B19044;

void func_80000844(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x27E) = 0;
    M2C_FIELD(arg0, s8 *, 0x27F) = 0;
    M2C_FIELD(arg0, s16 *, 0x282) = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x288) = &D_80B19044;
}
