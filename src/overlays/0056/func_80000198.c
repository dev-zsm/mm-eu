// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000198(u8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x260), s16 *, 8) = 0;
}
