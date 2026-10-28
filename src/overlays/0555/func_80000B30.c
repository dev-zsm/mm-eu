// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80BA4C2C(u8 *, M2C_UNK);             /* extern */

void func_80000B30(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x284);
    if (temp_v0 == 0) {
        func_80BA4C2C(arg0, 2);
        M2C_FIELD(arg0, u16 *, 0x262) = (u16) (M2C_FIELD(arg0, u16 *, 0x262) | 0x400);
        M2C_FIELD(arg0, s16 *, 0x284) = (s16) (M2C_FIELD(arg0, s16 *, 0x284) + 1);
        return;
    }
    if ((temp_v0 == 1) && (func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0)) {
        func_80BA4C2C(arg0, 1);
        M2C_FIELD(arg0, u16 *, 0x262) = (u16) (M2C_FIELD(arg0, u16 *, 0x262) & 0xFBFF);
        M2C_FIELD(arg0, s16 *, 0x284) = (s16) (M2C_FIELD(arg0, s16 *, 0x284) + 1);
    }
}
