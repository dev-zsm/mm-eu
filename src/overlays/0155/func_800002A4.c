// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800002A4(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x168) = (s32) (M2C_FIELD(arg0, s32 *, 0x168) + 1);
}
