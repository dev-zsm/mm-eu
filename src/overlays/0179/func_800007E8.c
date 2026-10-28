// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800007E8(u8 *arg0) {
    u8 *var_v0;

    var_v0 = M2C_FIELD(arg0, u8 **, 0x1CC0);
    if (var_v0 != NULL) {
        do {
            if (M2C_FIELD(var_v0, s16 *, 0) == 0x1B3) {
                M2C_FIELD(var_v0, s16 *, 0x30A) = 1;
            }
            var_v0 = M2C_FIELD(var_v0, u8 **, 0x12C);
        } while (var_v0 != NULL);
    }
}
