#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BCD59C(u8 *);                      /* extern */
extern M2C_UNK D_60011C0;
extern M2C_UNK D_6007908;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BCD550;
extern M2C_UNK D_80BCDBB0;

void func_80000000(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41C80000);
    func_80136ED0(arg1, arg0 + 0x144, &D_6007908, &D_60011C0, arg0 + 0x188, arg0 + 0x200, 0x14);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s32 *, 0x28C) = (s32) temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s32 *, 0x290) = 1;
        if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0x80) && ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) != 3) || (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) == 0))) {
            func_800B6490(arg0);
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x2F0) = 0x1E;
        M2C_FIELD(arg0, s16 *, 0x2F2) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x2F4) = 0;
        if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0x80) || ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) == 3) && (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) != 0))) {
            func_800B6490(arg0);
        }
    }
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
    func_800E1134(arg1, arg0 + 0x2B0, arg0, &D_80BCDBB0);
    if (M2C_FIELD(arg0, s32 *, 0x28C) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80BCD550;
        return;
    }
    func_80BCD59C(arg0);
}
