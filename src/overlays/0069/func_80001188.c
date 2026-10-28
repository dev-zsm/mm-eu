// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001188(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x380) = -1;
    M2C_FIELD(arg0, s16 *, 0x384) = 0;
}
