// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80AE4060(u8 *);                      /* extern */
extern f32 D_80AE61A4;

void func_800009E8(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
    if (temp_f0 < 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f0 + D_80AE61A4);
    }
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800FFCBC(arg0 + 0x3E0, 0, 1, 0x12C, 0);
    func_800FFCBC(arg0 + 0x3E6, 0, 1, 0x12C, 0);
    if (func_80137C58(arg0 + 0x190, M2C_FIELD(arg0, s32 *, 0x1A0)) != 0) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        func_80AE4060(arg0);
    }
}
