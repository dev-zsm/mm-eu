// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8017A1B0(s32, s32, s32, M2C_UNK);      /* extern */

void func_8017A310(s32 arg0) {
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    do {
        var_s0 = 0;
loop_2:
        func_8017A1B0(arg0, var_s0, var_s2, 1);
        var_s0 += 1;
        if (var_s0 != 0x140) {
            goto loop_2;
        }
        var_s2 += 1;
    } while (var_s2 != 0xF0);
}
