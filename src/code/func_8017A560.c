// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80089610(M2C_UNK);                     /* extern */
M2C_UNK func_8017A454();                            /* extern */
extern s32 D_80000300;

void func_8017A560(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_80000300 == 0) {
        var_v0 = 1;
    }
    if (var_v0 == 0) {
        func_8017A454();
        func_80089610(0);
loop_4:
        goto loop_4;
    }
}
