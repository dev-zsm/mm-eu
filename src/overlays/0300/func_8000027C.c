// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000027C(u8 *arg0) {
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
    if (temp_f0 > 3.0f) {
        var_f2 = 3.0f;
    } else {
        var_f2 = temp_f0;
    }
    if (M2C_FIELD(arg0, f32 *, 0x4D4) < var_f2) {
        M2C_FIELD(arg0, f32 *, 0x4D4) = var_f2;
    }
}
