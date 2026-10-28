// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80830238(M2C_UNK, s32, M2C_UNK);           /* extern */

s32 func_8001AD34(s32 arg0, M2C_UNK arg1) {
    if (func_80830238(arg1, arg0, arg1) != 0) {
        return 1;
    }
    return 0;
}
