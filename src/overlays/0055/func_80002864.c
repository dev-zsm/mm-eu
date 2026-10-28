// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80002864(u8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x23C) = arg1;
    return 1;
}
