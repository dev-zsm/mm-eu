// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800008F0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, u8 *, 0x2B1) = (u8) M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2B8), u8 *, 1);
    return 0;
}
