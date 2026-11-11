#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BBED8(u8 *, s32, u8 *, M2C_UNK); /* extern */
M2C_UNK func_80136ED0(u8 *, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80A99BB8(u8 *, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK D_60082C8;
extern M2C_UNK D_601D518;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A9D848;
extern M2C_UNK D_80A9E97C;
extern f32 D_80A9EB64;

void func_800005D8(u8 *arg0, u8 *arg1) {
    func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 6);
    M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9D848;
    M2C_FIELD(arg0, s16 *, 0x116) = 0x8E8;
    func_80136ED0(arg1, arg0 + 0x2A0, &D_601D518, &D_60082C8, arg0 + 0x2E4, arg0 + 0x302, 4);
    func_80A99BB8(arg0, 2, 0, 0);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A9E97C;
    M2C_FIELD(arg0, s32 *, 0xC8) = 0;
    M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) | 0x23);
    M2C_FIELD(arg0, f32 *, 0x3D8) = (f32) D_80A9EB64;
    M2C_FIELD(arg0, s32 *, 0x3C8) = 0x3C;
    M2C_FIELD(arg1, s8 *, 0x170C7) = 1;
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) & 0xF7);
}
