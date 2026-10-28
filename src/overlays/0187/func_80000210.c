// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000210(u8 *arg0) {
    return (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF) + 0x200;
}
