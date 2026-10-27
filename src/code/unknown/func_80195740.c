// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_801956D0(s32);                             /* extern */

s32 func_80195740(s32 *arg0, s32 *arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    var_s0 = *arg0;
    var_s1 = *arg1;
loop_1:
    temp_v0 = func_801956D0(var_s0);
    if (temp_v0 == 0) {
        return -1;
    }
    if (var_s1 >= temp_v0) {
        var_s1 -= temp_v0;
        var_s0 += 1;
        goto loop_1;
    }
    *arg0 = var_s0;
    *arg1 = var_s1;
    return 0;
}
