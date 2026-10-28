// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFAD8(u8 *, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80182B28(M2C_UNK *, u8 *);           /* extern */
extern M2C_UNK D_80A7E090;
extern M2C_UNK D_80A7E09C;
extern M2C_UNK D_80A7E0A8;
extern f32 D_80A7E324;

void func_80004418(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    if (arg1 == 3) {
        func_80182B28(&D_80A7E090, arg4 + 0x3A8);
        func_800FFAD8(arg4 + 0x3A4, M2C_FIELD(arg4, f32 *, 0x3AC) - M2C_FIELD(arg4, f32 *, 0x28), 0x3F4CCCCD, 0x41200000, D_80A7E324);
        if (M2C_FIELD(arg4, u16 *, 0x374) & 2) {
            func_80182B28(&D_80A7E09C, arg4 + 0x3B4);
            return;
        }
        func_80182B28(&D_80A7E0A8, arg4 + 0x3B4);
    }
}
