// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000200C(u8 *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x32C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x330) = arg2;
}
