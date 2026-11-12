#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_8012F5DC(s16);                             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80136E1C(u8 *, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80958C30(u8 *, M2C_UNK *);           /* extern */
s32 func_80958CC4(u8 *);                          /* extern */
M2C_UNK func_80958DC0(u8 *, u8 *);              /* extern */
M2C_UNK func_80958F8C(u8 *, u8 *);              /* extern */
M2C_UNK func_809592FC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_6000304;
extern M2C_UNK D_6001494;
extern M2C_UNK D_6006470;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_8095A954;

void func_800014D8(u8 *arg0, u8 *arg1) {
    f32 sp3C;
    s32 sp30;
    s32 temp_a1;

    sp3C = (f32) func_80134AE8(&D_6000304);
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41F00000);
    temp_a1 = arg0 + 0x144;
    sp30 = temp_a1;
    func_80136E1C(arg1, temp_a1, &D_6006470, 0, arg0 + 0x188, arg0 + 0x23C, 0x1E);
    func_80137788(sp30, &D_6001494, 0x3F800000, 0.0f, sp3C, 1, 0.0f);
    M2C_FIELD(arg0, s32 *, 0x530) = func_80958CC4(arg1);
    func_80958F8C(arg0, arg1);
    M2C_FIELD(arg0, u16 *, 0x5C2) = 0U;
    M2C_FIELD(arg0, s8 *, 0x5C4) = 0;
    func_80958DC0(arg0, arg1);
    if (!(M2C_FIELD(arg0, s16 *, 0x1C) & 0xF)) {
        M2C_FIELD(arg0, u16 *, 0x5C2) = (u16) (M2C_FIELD(arg0, u16 *, 0x5C2) | 0x20);
    }
    if (!(M2C_FIELD(arg0, u16 *, 0x5C2) & 0x20)) {
        func_809592FC(arg0, 0x3F000000, 0x3F800000);
    } else {
        func_809592FC(arg0, 0x3F400000, 0x3F800000);
    }
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x51C) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    func_80958C30(arg0, &D_8095A954);
    if (func_8012F5DC(M2C_FIELD(arg1, s16 *, 0xA4)) >= 0x1E) {
        func_800B6490(arg0);
    }
}
