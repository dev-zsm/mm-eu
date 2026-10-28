// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AB80B0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80ABA510;

void func_800007EC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3B0);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3B0) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x3B0);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x3B0) = 0xA;
        M2C_FIELD(arg0, f32 *, 0x68) = -1.0f;
        func_80AB80B0(arg0 + 0x150, &D_80ABA510, 8, arg0);
        M2C_FIELD(arg0, s16 *, 0x3B2) = 8;
    }
}
