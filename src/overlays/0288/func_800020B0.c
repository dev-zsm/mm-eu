// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, s16);   /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_809D5380(u8 *, s32);                 /* extern */
extern f32 D_809D6A74;

void func_800020B0(u8 *arg0, s32 arg1) {
    func_800B8C4C(arg0, 0x3006);
    func_80137070(arg0 + 0x3C8);
    func_800FFBF8(arg0 + 0x70, 0x41000000, 0x3F800000, 0x40800000);
    func_800FFDD8(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 5, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x358));
    func_800FFBF8(arg0 + 0x358, 0x457A0000, 0x3F800000, 0x43C80000);
    if ((M2C_FIELD(arg0, s16 *, 0x162) == 0) || (M2C_FIELD(arg0, f32 *, 0x94) <= D_809D6A74)) {
        func_809D5380(arg0, arg1);
    }
}
