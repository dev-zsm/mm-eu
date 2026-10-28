// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F1944(M2C_UNK);                     /* extern */
s32 func_800F1984(M2C_UNK);                         /* extern */
M2C_UNK func_800F1B24(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_800FD0AC(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_80184E80(s32);                             /* extern */
extern f32 D_80A316B4;

void func_8000013C(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 var_f0;
    u8 temp_v0;
    u8 temp_v0_2;

    if (func_80184E80(arg0 + 0x144) != 0) {
        func_800B6490(arg0);
        func_800F1D6C(0x7B);
        func_800FD0AC(arg1, 0.0f, 0x44548000, 0x3E4CCCCD, 0.0f);
        return;
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x154);
    M2C_FIELD(arg0, s16 *, 0x1BC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1BC) + 1);
    if (temp_f0 < 20.0f) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x1C1);
        if ((s32) temp_v0 < 0xF2) {
            M2C_FIELD(arg0, u8 *, 0x1C1) = (u8) (temp_v0 + 0xD);
        } else {
            M2C_FIELD(arg0, u8 *, 0x1C1) = 0xFFU;
        }
    } else if (temp_f0 > 70.0f) {
        temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x1C1);
        if ((s32) temp_v0_2 >= 0xE) {
            M2C_FIELD(arg0, u8 *, 0x1C1) = (u8) (temp_v0_2 - 0xD);
        } else {
            M2C_FIELD(arg0, u8 *, 0x1C1) = 0U;
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x1C1) = 0xFFU;
    }
    var_f0 = (f32) M2C_FIELD(arg0, u8 *, 0x1C1) * D_80A316B4;
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    } else if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    func_800FD0AC(arg1, var_f0, 0x44548000, 0x3E4CCCCD, 0.0f);
    if (func_800F1E2C() != 0x7B) {
        if (func_800F1984(0x7B) != 0) {
            func_800F1B24(0x7B, arg0);
            return;
        }
        func_800F1944(0x7B);
    }
}
