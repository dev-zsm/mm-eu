// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_809794F0(u8 *, u8 *, u8 *);      /* extern */
M2C_UNK func_8097A770(u8 *);                      /* extern */

void func_800006E4(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, f32 *, 0x15C) < 4.0f) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    } else {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    }
    func_800FFC68(arg0 + 0xC4, 0x3F800000, 0x44480000);
    func_800FFBF8(arg0 + 0xCC, 0x41C80000, 0x3F800000, 0x40200000);
    if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 1)) {
        func_809794F0(arg1, arg0, arg0 + 0x24);
    }
    if ((func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0) && (M2C_FIELD(arg0, f32 *, 0xC4) == 0.0f)) {
        func_8097A770(arg0);
    }
    M2C_FIELD(arg0, s16 *, 0x3D0) = (s16) (M2C_FIELD(arg0, s16 *, 0x3D0) + 1);
}
