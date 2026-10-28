// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BCD59C();                            /* extern */

void func_800002C0(u8 *arg0, u8 *arg1) {
    u8 *var_v0;

    var_v0 = M2C_FIELD(arg1, u8 **, 0x1CE4);
    if (var_v0 != NULL) {
        do {
            if (M2C_FIELD(var_v0, s16 *, 0) == 0x26D) {
                M2C_FIELD(arg0, u8 **, 0x2A8) = var_v0;
            }
            var_v0 = M2C_FIELD(var_v0, u8 **, 0x12C);
        } while (var_v0 != NULL);
    }
    func_80BCD59C();
}
