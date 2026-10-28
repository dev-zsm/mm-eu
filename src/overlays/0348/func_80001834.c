// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80A3C768(u8 *, s32);                 /* extern */

void func_80001834(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (M2C_FIELD(arg0, s16 *, 0xBC) - 0x700);
    func_800FEE3C(arg0 + 0xC4, 0x44D48000, 0x432A0000, arg0);
    M2C_FIELD(arg0, s16 *, 0x190) = (s16) (M2C_FIELD(arg0, s16 *, 0x190) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x190) == 0) {
        M2C_FIELD(arg0, s16 *, 0x190) = 0x1E;
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 0x19) {
        func_80A3C768(arg0, arg1);
    }
}
