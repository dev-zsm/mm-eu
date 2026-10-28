// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001938(u8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x34C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x34C) = 0;
    }
}
