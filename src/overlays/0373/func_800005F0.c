// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800005F0(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x170E9) = 0;
}
