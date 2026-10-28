// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80005F08(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0xD5C) >= 0) {
        M2C_FIELD(arg0, s8 *, 0xD5C) = arg1;
        M2C_FIELD(arg0, s8 *, 0xB5F) = 0;
    }
}
