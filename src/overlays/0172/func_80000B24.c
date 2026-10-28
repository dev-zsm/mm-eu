// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, s16, s32); /* extern */
M2C_UNK func_8093CD18(u8 *, s32, M2C_UNK);        /* extern */
s32 func_8093D0A0(u8 *, s32);                     /* extern */

void func_80000B24(u8 *arg0, s32 arg1) {
    if (func_8093D0A0(arg0, arg1) == 0) {
        func_800B6490(arg0);
        return;
    }
    func_800FFCBC(arg0 + 0x30, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C8), 5, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2D4), 0);
    func_800FFBF8(arg0 + 0x2D4, 0x459C4000, 0x3F800000, 0x42C80000);
    func_800FFBF8(arg0 + 0x68, 0x40A00000, 0x3E99999A, 0x3F800000);
    func_8093CD18(arg0, arg1, 2);
}
