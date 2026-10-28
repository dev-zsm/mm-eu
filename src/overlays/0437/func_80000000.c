// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80000000(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2C4);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2C4) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x2C4);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x2C2) = (s16) (M2C_FIELD(arg0, s16 *, 0x2C2) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x2C2) >= 3) {
            M2C_FIELD(arg0, s16 *, 0x2C0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2C0) - 1);
            if (M2C_FIELD(arg0, s16 *, 0x2C0) < 0) {
                M2C_FIELD(arg0, s16 *, 0x2C4) = func_800FF250(0x1E, 0x1E, arg0);
                M2C_FIELD(arg0, s16 *, 0x2C0) = 2;
                if (func_8008704C() > 0.5f) {
                    M2C_FIELD(arg0, s16 *, 0x2C0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2C0) + 1);
                }
            }
            M2C_FIELD(arg0, s16 *, 0x2C2) = 0;
        }
    }
}
