// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_80B6A720(u8 *, s32, M2C_UNK);        /* extern */
extern f32 D_80B6FA74;
extern f32 D_80B6FA78;
extern f32 D_80B6FA7C;

void func_80003CF0(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    s16 temp_v0;
    s16 temp_v0_2;

    if (M2C_FIELD(arg0, s16 *, 0x2BA) == 0xB) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x2B8);
        if ((temp_v0 != 0) && (temp_v0 < 0x3C)) {
            M2C_FIELD(arg0, s16 *, 0x2BA) = 0xA;
        }
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
        if (temp_f0 < 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f0 + D_80B6FA74);
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 0x2B6) == 0) && (M2C_FIELD(arg0, s16 *, 0x2B8) == 0) && ((M2C_FIELD(arg0, s32 *, 4) & 0x2000) != 0x2000) && (M2C_FIELD(arg0, u16 *, 0x90) & 1) && ((M2C_FIELD(arg0, s8 *, 0x2D8) = 0, func_80B6A720(arg0, arg1, 1), temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x2BA), (temp_v0_2 == 0xB)) || (temp_v0_2 == 0xA))) {
        func_800BF550(arg1, arg0, arg0 + 0x310, 0xF, 2, D_80B6FA78, D_80B6FA7C);
        M2C_FIELD(arg0, s16 *, 0x2B8) = 0;
        M2C_FIELD(arg0, s16 *, 0x2BA) = 0;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x400);
    }
}
