// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80001DEC(u8 *arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    if ((M2C_FIELD(arg0, u8 *, 0x1F2C) == 0) && (M2C_FIELD(arg0, s16 *, 0xA4) == 0x38) && (arg1 == 0x15)) {
        M2C_FIELD(arg4, s16 *, 4) = -0x5E24;
    }
    return 0;
}
