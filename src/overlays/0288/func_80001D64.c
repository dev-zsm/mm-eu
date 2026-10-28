// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFC68(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_800FFDD8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_809D4D88(u8 *, s32);                 /* extern */
M2C_UNK func_809D5000(u8 *, s32);                 /* extern */

void func_80001D64(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x3C8);
    func_800FFC68(arg0 + 0x70, 0x3F800000, 0x40200000);
    func_800FFDD8(arg0 + 0xBC, 0, 2, 0x400);
    func_800FFDD8(arg0 + 0xC0, 0, 2, 0x400);
    if (M2C_FIELD(arg0, s16 *, 0x162) == 0) {
        func_809D5000(arg0, arg1);
    }
    func_809D4D88(arg0, arg1);
}
