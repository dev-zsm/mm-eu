#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */

void func_80000AFC(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x190);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x190) = (s16) (temp_v0 - 1);
    }
    func_800FEE3C(arg0 + 0x58, 0, 0x39B24207);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x60) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x5C) = temp_f0;
    if (M2C_FIELD(arg0, s16 *, 0x190) == 0) {
        func_800A8248(arg1, arg0, arg0 + 0x24, 0xA0);
        func_800B6490(arg0);
    }
}
