// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800029A8(u8 *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x316) = arg1;
    M2C_FIELD(arg0, s16 *, 0x318) = arg2;
}
