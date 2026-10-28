// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80002884(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3) {
    if ((arg1 == 0x14) || (arg1 == 0x15)) {
        *arg2 = 0;
    }
    return 0;
}
