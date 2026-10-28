// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B6CA18(s32, u8 *);                 /* extern */
M2C_UNK func_80B6CC90(u8 *);                      /* extern */

void func_800027AC(u8 *arg0, s32 arg1) {
    f32 sp2C;
    s16 temp_v0;

    sp2C = M2C_FIELD(arg0, f32 *, 0x160);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 1, 0xFA0, 1);
    if (M2C_FIELD(arg0, f32 *, 0x68) >= 5.0f) {
        func_80B6CA18(arg1, arg0 + 0x58C);
        func_80B6CA18(arg1, arg0 + 0x580);
    }
    M2C_FIELD(arg0, s8 *, 0x2D8) = 0;
    if ((M2C_FIELD(arg0, f32 *, 0x2DC) <= sp2C) && (M2C_FIELD(arg0, u16 *, 0x90) & 3)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
        M2C_FIELD(arg0, s8 *, 0x400) = 1;
        M2C_FIELD(arg0, s8 *, 0x3E8) = 3;
        M2C_FIELD(arg0, s8 *, 0x44C) = 2;
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x88);
        func_80B6CC90(arg0);
    }
}
