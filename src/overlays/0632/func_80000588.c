// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000588(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s16 *arg4, u8 *arg5) {
    if (arg1 == 5) {
        *arg4 += M2C_FIELD(arg5, s16 *, 0x2B0);
    }
    return 0;
}
