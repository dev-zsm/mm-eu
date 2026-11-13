#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0466.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_80B03908(u8 *);                      /* extern */
extern f32 D_80B06544;
extern f32 D_80B06548;

void func_80001804(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    if (M2C_FIELD(arg0, s16 *, 0x3F4) == 0xB) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x3F2);
        if ((temp_v0 != 0) && (temp_v0 < 0x3C)) {
            M2C_FIELD(arg0, s16 *, 0x3F4) = 0xA;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 0x2CC) == 0) && (M2C_FIELD(arg0, s16 *, 0x3F2) == 0)) {
        if ((M2C_FIELD(arg0, s16 *, 0x3F4) == 0xB) || (M2C_FIELD(arg0, s16 *, 0x3F4) == 0xA)) {
            func_800BF550(arg1, arg0, arg0 + 0x408, 0xB, 2, D_80B06544, D_80B06548);
            M2C_FIELD(arg0, s16 *, 0x3F2) = 0;
            M2C_FIELD(arg0, s16 *, 0x3F4) = 0;
        }
        func_80B03908(arg0);
    }
}
