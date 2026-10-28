// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
M2C_UNK func_80832628(u8 *, M2C_UNK *, s16 *, M2C_UNK, s32); /* extern */

void func_80028550(s32 arg0, u8 *arg1) {
    M2C_UNK sp24;
    s16 sp22;

    M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) | 0x20);
    func_80832628(arg1, &sp24, &sp22, 0x3C9374BC, arg0);
    func_800FEC70(arg1 + 0xAD4, sp22, 0x258);
}
