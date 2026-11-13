#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
s32 func_800B5B20(u8 *, s32);                     /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E090C(u8 *, u8 *);              /* extern */
M2C_UNK func_800E0C20(u8 *, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136E1C(u8 *, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B555F0(u8 *, u8 *);              /* extern */
M2C_UNK func_80B55CD0(u8 *);                      /* extern */
extern M2C_UNK D_6005EF8;
extern M2C_UNK D_60064E0;
extern M2C_UNK D_800B3F30;
extern s32 D_801EAB9C;
extern M2C_UNK D_80B58180;
extern M2C_UNK D_80B58190;
extern M2C_UNK D_80B5819C;
extern M2C_UNK D_80B581C0;
extern f32 D_80B58210;

void func_8000052C(u8 *arg0, u8 *arg1) {
    u8 *sp34;
    u8 *temp_a1;

    func_80B555F0(arg0, arg1);
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136E1C(arg1, arg0 + 0x1E4, &D_6005EF8, &D_60064E0, arg0 + 0x2F4, arg0 + 0x36C, 0x14);
    temp_a1 = arg0 + 0x144;
    sp34 = temp_a1;
    func_800E090C(arg1, temp_a1);
    func_800E0C20(arg1, temp_a1, arg0, &D_80B58180, arg0 + 0x164);
    func_800E731C(arg0 + 0xA0, &D_80B5819C, &D_80B58190);
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF) != 0) {
        func_800B6490(arg0);
    }
    func_800FF8DC(arg0, &D_80B581C0);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80B58210;
    M2C_FIELD(arg0, s8 *, 0x11F) = 0x55;
    M2C_FIELD(arg0, s16 *, 0x3F2) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E4) = -1;
    M2C_FIELD(arg0, s16 *, 0x3FC) = 0;
    M2C_FIELD(arg0, s16 *, 0x3FA) = 0;
    M2C_FIELD(arg0, s8 *, 0x403) = 0;
    M2C_FIELD(arg0, s16 *, 0x3FE) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        M2C_FIELD(arg0, s16 *, 0x3F4) = 1;
        M2C_FIELD(arg0, s16 *, 0x3F6) = 1;
        M2C_FIELD(arg0, s16 *, 0x3F8) = 0;
    }
    if ((M2C_FIELD(arg1, s16 *, 0xA4) == 0x43) && (D_801EAB9C == 1) && (M2C_FIELD(arg1, u16 *, 0x1F36) == 0)) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x100000);
    }
    func_80B55CD0(arg0);
}
