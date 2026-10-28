// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000104(u8 *arg0, M2C_UNK arg1) {
    return (M2C_FIELD(arg0, u8 *, 0x17C) & 8) == 0;
}
