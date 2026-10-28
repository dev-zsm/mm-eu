// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000748(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg1, u8 *, 0x1CA5) | 8);
}
