#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
s16 func_808A530C(u8 *);                          /* extern */

void func_80000C7C(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_v1;

    if (M2C_FIELD(arg0, s16 *, 0x310) != 0) {
        M2C_FIELD(arg0, s16 *, 0x310) = (s16) (M2C_FIELD(arg0, s16 *, 0x310) - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x310) < 8) {
        func_800FFDD8(arg0 + 0x32, func_808A530C(arg0), 3, 0x1FFE);
    } else {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x2AA8);
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x310);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v0_2 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x310) = (s16) (temp_v0_2 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x310);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, u16 *, 0x18C) = (u16) (M2C_FIELD(arg0, u16 *, 0x18C) & 0xFFFE);
    }
}
