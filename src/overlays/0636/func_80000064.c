// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801E6F00;

void func_80000064(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x144) = (s8) D_801E6F00;
}
