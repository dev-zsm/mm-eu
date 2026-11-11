#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0586.h"

M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
u8 *func_80BC2F40(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BC301C(u8 *, M2C_UNK);             /* extern */

s32 func_800010A4(u8 *arg0, s32 arg1, M2C_UNK arg2) {
    s32 sp24;
    u8 *sp20;
    u8 *temp_v0;

    sp24 = 0;
    sp20 = func_80BC2F40(arg0, arg1, 4, 0xA4);
    temp_v0 = func_80BC2F40(arg0, arg1, 4, 0x234);
    if ((sp20 != NULL) && (M2C_FIELD(sp20, s32 *, 0x138) != 0) && (temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) != 0)) {
        func_80BC301C(arg0, 0);
        func_8013B284(arg0 + 0x4C2, 3, 7);
        M2C_FIELD(arg0, u8 **, 0x368) = sp20;
        M2C_FIELD(arg0, u16 *, 0x4C2) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C2) | 0x20);
        sp24 = 1;
    }
    return sp24;
}
