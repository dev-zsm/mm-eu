// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, u8 *);                  /* extern */
f32 func_8017B9A8(u8 *, u8 *);                  /* extern */
extern f32 D_80A7E30C;

void func_800039E4(u8 *arg0, u8 *arg1) {
    f32 temp_f20;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1D08);
    if (var_s0 != NULL) {
        temp_f20 = D_80A7E30C;
        do {
            if ((M2C_FIELD(var_s0, s16 *, 0) == 0x17) && (M2C_FIELD(var_s0, s16 *, 0x1C) < 0) && (M2C_FIELD(arg0, s8 *, 3) == M2C_FIELD(var_s0, s8 *, 3)) && (func_8017B9A8(arg0 + 0x24, var_s0 + 0x24) < temp_f20)) {
                M2C_FIELD(var_s0, s8 *, 0x276) = 0x14;
                M2C_FIELD(var_s0, s16 *, 0x274) = func_800B6A58(var_s0, arg0);
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        } while (var_s0 != NULL);
    }
}
