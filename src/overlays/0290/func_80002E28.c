// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_801A0070(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_809DC130(u8 *, s32, M2C_UNK);        /* extern */
extern M2C_UNK D_809EE770;

void func_80002E28(u8 *arg0, s32 arg1) {
    func_800B8C4C(arg0, 0x3014);
    if (M2C_FIELD(arg0, s16 *, 0x14C) == 0xD) {
        func_801A0070(&D_809EE770, 0x3A57);
    }
    func_80137070(arg0 + 0x190);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_809DC130(arg0, arg1, 1);
        M2C_FIELD(arg0, s16 *, 0x156) = 5;
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 3, 0x4000);
}
