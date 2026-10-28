// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800049F8(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3) {
    if ((arg1 == 1) || (arg1 == 2) || (arg1 == 3)) {
        *arg2 = 0;
    }
    return 0;
}
