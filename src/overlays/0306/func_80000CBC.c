// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9F3C(s32, s32, s32, s32, f32 *, M2C_UNK *); /* extern */
M2C_UNK func_80A0C4BC(u8 *);                      /* extern */
M2C_UNK func_80A0C6A0(u8 *, s32);                 /* extern */
M2C_UNK func_80A0CFA4(u8 *);                      /* extern */

void func_80000CBC(u8 *arg0, s32 arg1) {
    M2C_UNK sp2C;
    f32 sp28;

    if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), s16 *, 0x1C) == 1) {
        if (func_800C9F3C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), &sp28, &sp2C) != 0) {
            M2C_FIELD(arg0, f32 *, 0x8C) = (f32) (sp28 - M2C_FIELD(arg0, f32 *, 0x28));
        } else {
            M2C_FIELD(arg0, f32 *, 0x8C) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        }
        func_80A0C4BC(arg0);
        func_80A0C6A0(arg0, arg1);
        func_80A0CFA4(arg0);
    }
}
