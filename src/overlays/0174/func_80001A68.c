#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
extern f32 D_80941E68;
extern f32 D_80941E6C;
extern f32 D_80941E70;

void func_80001A68(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;

    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x20);
    if (D_80941E68 < M2C_FIELD(arg0, f32 *, 0x98)) {
        func_800B6490(arg0);
    }
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x3EC), 2, 0x80, 0x40);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (M2C_FIELD(arg0, f32 *, 0x70) < 16.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (M2C_FIELD(arg0, f32 *, 0x70) + 0.5f);
    }
    if ((M2C_FIELD(arg0, f32 *, 0x3E4) + 1000.0f) < M2C_FIELD(arg0, f32 *, 0x28)) {
        temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x68);
        if (temp_f0_2 > 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x68) = (f32) (temp_f0_2 - D_80941E6C);
        }
    } else {
        temp_f0_3 = M2C_FIELD(arg0, f32 *, 0x68);
        if (temp_f0_3 < 4.0f) {
            M2C_FIELD(arg0, f32 *, 0x68) = (f32) (temp_f0_3 + D_80941E70);
        }
    }
}
