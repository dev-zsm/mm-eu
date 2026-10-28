// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_800007A8(u8 *arg0) {
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg0, u8 **, 0x1CD8);
    if (var_s0 != NULL) {
        do {
            func_800B6490(var_s0);
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        } while (var_s0 != NULL);
    }
}
