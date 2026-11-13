#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
s32 func_800E0160(M2C_UNK);                         /* extern */
M2C_UNK func_800E0F5C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800E10CC(M2C_UNK, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, s32, M2C_UNK *);      /* extern */
M2C_UNK func_80136ED0(M2C_UNK, u8 *, M2C_UNK *, M2C_UNK, u8 *, u8 *, s32); /* extern */
s32 func_80B73400(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B7356C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B73658(u8 *, M2C_UNK);             /* extern */
s32 func_80B737DC(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B738FC(u8 *);                      /* extern */
M2C_UNK func_80B75BE8(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_6015C28;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B76130;
extern M2C_UNK D_80B7615C;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    u8 *sp30;
    u8 *temp_a1;

    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    M2C_FIELD(arg0, s32 *, 0x200) = 0;
    M2C_FIELD(arg0, s16 *, 0x310) = 0;
    M2C_FIELD(arg0, s16 *, 0x320) = 0;
    M2C_FIELD(arg0, s16 *, 0x31A) = 0;
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1)) {
        func_80B75BE8(arg0, 0, 1);
    } else {
        func_80B75BE8(arg0, 5, 2);
    }
    M2C_FIELD(arg0, s16 *, 0x31E) = 0;
    M2C_FIELD(arg0, s16 *, 0x31C) = 0x64;
    M2C_FIELD(arg0, s32 *, 0x204) = (s32) ((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xF000) >> 0xC);
    if (func_80B73400(arg0, arg1) == 0) {
        func_800B6490(arg0);
        return;
    }
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41900000);
    func_80136ED0(arg1, arg0 + 0x144, &D_6015C28, 0, arg0 + 0x208, arg0 + 0x28C, 0x16);
    func_80B7356C(arg0, arg1);
    temp_a1 = arg0 + 0x18C;
    sp30 = temp_a1;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80B76130);
    func_800E731C(arg0 + 0xA0, func_800E0160(0x16), &D_80B7615C);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    if (func_80B737DC(arg0, arg1) == 1) {
        func_80B738FC(arg0);
        return;
    }
    func_80B73658(arg0, arg1);
}
