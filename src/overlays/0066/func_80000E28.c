#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800FEE3C(s32, f32, M2C_UNK);           /* extern */

void func_80000E28(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    if (func_800FEE3C(arg0 + 0x58, 0, 0x3AC49BA6) != 0) {
        func_800B6564(arg0, 0x3C23D70A);
        func_800A8248(arg1, arg0, arg0 + 0x24, 0x90);
        func_800B6490(arg0);
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x60) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x5C) = temp_f0;
}
