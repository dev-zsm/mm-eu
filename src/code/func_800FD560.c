// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u16 D_801EAE36;

s32 Environment_IsForcedSequenceDisabled(void) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801EAE36 != 0) {
        var_v1 = 1;
    }
    return var_v1;
}
