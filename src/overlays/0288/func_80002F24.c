// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80002F24(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3) {
    if ((arg1 >= 3) && (arg1 < 9)) {
        *arg2 = 0;
    }
    return 0;
}
