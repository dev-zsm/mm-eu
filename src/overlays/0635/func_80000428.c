// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A0070(u8 *, M2C_UNK, u8 *);     /* extern */

void func_80000428(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    u8 var_v1;

    var_v1 = M2C_FIELD(arg0, u8 *, 0xB7);
    if ((var_v1 & 1) && !(M2C_FIELD(arg0, u8 *, 0x1B8) & 1)) {
        func_801A0070(arg0 + 0xEC, 0x2822, arg0);
        var_v1 = M2C_FIELD(arg0, u8 *, 0xB7);
        M2C_FIELD(arg0, u8 *, 0x1B8) = var_v1;
    }
    if (var_v1 & 2) {
        M2C_FIELD(arg0, u8 *, 0xB7) = (u8) (var_v1 & 0xFFFD);
        M2C_FIELD(arg0, s16 *, 0x1B2) = 0x12C;
        M2C_FIELD(arg0, s16 *, 0x1B4) = 1;
    } else if (var_v1 & 4) {
        M2C_FIELD(arg0, u8 *, 0xB7) = (u8) (var_v1 & 0xFFFB);
        M2C_FIELD(arg0, s16 *, 0x1B2) = 0x12C;
        M2C_FIELD(arg0, s16 *, 0x1B4) = 2;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1B2);
    if (temp_v0 >= 0x10) {
        M2C_FIELD(arg0, s16 *, 0x1B2) = (s16) (temp_v0 - 0xF);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1B2) = 0;
}
