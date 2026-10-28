// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 *D_801EB7E0;

void func_8000007C(s32 arg0) {
    M2C_FIELD(D_801EB7E0, s16 *, 0x454) = 0;
}
