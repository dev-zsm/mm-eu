// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_809D5268(u8 *, s32);                 /* extern */

void func_80001FE0(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x3C8);
    func_800B8C4C(arg0, 0x3006);
    func_800FFC68(arg0 + 0x70, 0x3F800000, 0x40200000);
    func_800FFDD8(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x1000);
    if (M2C_FIELD(arg0, s16 *, 0x162) == 0) {
        func_809D5268(arg0, arg1);
    }
}
