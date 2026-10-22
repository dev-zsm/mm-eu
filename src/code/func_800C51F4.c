// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 BgCheck_GetBccFlags(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != 0) {
        var_v1 = 1;
    }
    if (arg1 != 0) {
        var_v1 |= 2;
    }
    if (arg2 != 0) {
        var_v1 |= 4;
    }
    if (arg3 != 0) {
        var_v1 |= 8;
    }
    if (arg4 != 0) {
        var_v1 |= 0x10;
    }
    return var_v1;
}
