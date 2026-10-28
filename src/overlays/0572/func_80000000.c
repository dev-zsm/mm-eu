// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000000(u8 *arg0, u8 *arg1) {
    u8 *var_v0;

    var_v0 = M2C_FIELD(arg1, u8 **, 0x1CFC);
    if (var_v0 != NULL) {
loop_1:
        if ((M2C_FIELD(var_v0, s16 *, 0) == 0x254) && (arg0 != var_v0)) {
            M2C_FIELD(arg0, u8 **, 0x124) = var_v0;
            return;
        }
        var_v0 = M2C_FIELD(var_v0, u8 **, 0x12C);
        if (var_v0 == NULL) {

        } else {
            goto loop_1;
        }
    }
}
