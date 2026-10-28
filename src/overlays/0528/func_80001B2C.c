// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B7B90C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80B7BB7C();                                /* extern */
extern M2C_UNK D_80B7BE20;

void func_80001B2C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x14) = (s16) (temp_v0 - 1);
        return;
    }
    if (func_80B7BB7C() != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7BE20;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    if (M2C_FIELD(arg0, s16 *, 0x2F0) != 3) {
        func_80B7B90C(arg0, 3, 0);
    }
}
