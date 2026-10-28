// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FD0AC(u8 *, f32, f32, M2C_UNK, f32); /* extern */
M2C_UNK func_800FEE3C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FFCBC(s32, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80003724(u8 *arg0, u8 *arg1) {
    u8 *sp2C;
    f32 temp_f0;

    sp2C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x258), 5, 0x1000, 0x400);
    M2C_FIELD(arg0, u16 *, 0x25A) = (u16) (M2C_FIELD(arg0, u16 *, 0x25A) + 1);
    if (M2C_FIELD(arg0, s32 *, 0x234) == 0) {
        if (M2C_FIELD(arg0, u16 *, 0x264) & 0x20) {
            M2C_FIELD(arg0, f32 *, 0x240) = 0.0f;
        } else {
            func_800FEE3C(arg0 + 0x240, 0x3F800000, 0x3D4CCCCD);
        }
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x240);
        func_800FD0AC(arg1, temp_f0 * temp_f0, M2C_FIELD(sp2C, f32 *, 0xF4) + 780.0f, 0x3E4CCCCD, 0.5f);
    }
}
