#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80984DB0(u8 *, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80984F4C(u8 *, s32);                 /* extern */
extern M2C_UNK D_6001EFC;
extern M2C_UNK D_600A808;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809850EC;
extern M2C_UNK D_80985210;
extern M2C_UNK D_809856AC;
extern M2C_UNK D_80985AE0;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    temp_a1 = arg0 + 0x194;
    sp34 = temp_a1;
    func_80136ED0(arg1, temp_a1, &D_600A808, 0, arg0 + 0x1D8, arg0 + 0x268, 0x18);
    func_801378E0(sp34, &D_6001EFC);
    func_800E1134(arg1, arg0 + 0x148, arg0, &D_80985AE0);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, s16 *, 0x312) = -1;
    M2C_FIELD(arg0, s16 *, 0x314) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809856AC;
    func_80984F4C(arg0, arg1);
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 1) == 1) {
        func_80984DB0(arg0, 2, 0, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x31C) = &D_80985210;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) & 2) {
            func_800B6490(arg0);
            return;
        }
        goto block_4;
    }
    func_80984DB0(arg0, 1, 0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x31C) = &D_809850EC;
    M2C_FIELD(arg0, f32 *, 0x70) = 1.5f;
    block_4:
    M2C_FIELD(arg0, s16 *, 0x310) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, f32 *, 0x78) = -4.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF48) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF48) & 0xF7);
}
