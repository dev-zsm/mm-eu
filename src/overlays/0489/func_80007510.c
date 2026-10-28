// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B2FC0C;

void func_80007510(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2F0) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2FC0C;
}
