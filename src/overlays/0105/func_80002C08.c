// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_808C72D4(u8 *);                      /* extern */

void func_80002C08(u8 *arg0, u8 *arg1) {
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 8, 0x1000, 0x100);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x40A00000);
    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg1, s8 *, 0x170C7) = 0x1B;
        func_808C72D4(arg0);
    }
}
