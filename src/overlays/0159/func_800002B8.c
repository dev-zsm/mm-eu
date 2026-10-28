// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800002B8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x1E4) = (s8) (((s16) M2C_FIELD(arg0, s16 *, 0x14) >> 1) & 3);
}
