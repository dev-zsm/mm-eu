// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 __osSpGetStatus(void);

s32 osSpTaskYielded(s32 *arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = __osSpGetStatus();
    if (temp_v0 & 0x100) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    if (temp_v0 & 0x80) {
        arg0[1] = arg0[1] | var_v1;
        arg0[1] = arg0[1] & ~2;
    }
    return var_v1;
}
