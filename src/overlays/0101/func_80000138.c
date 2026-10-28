// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000138(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg1, u8 **, 0x124) = arg0;
    M2C_FIELD(arg1, u8 **, 0x34C) = arg0;
    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        M2C_FIELD(arg0, s32 *, 0x124) = 0;
        M2C_FIELD(arg1, s32 *, 0x120) = 0;
        return 1;
    }
    return 0;
}
