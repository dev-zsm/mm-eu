// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800014CC(s32 arg0, u8 *arg1, M2C_UNK (*arg2)(u8 *)) {
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CF0);
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, s16 *, 0) == 0x212) {
                arg2(var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        } while (var_s0 != NULL);
    }
}
