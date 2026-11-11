#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
s32 func_800B5B20(s32, s16);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80A4C794(u8 *);                      /* extern */
extern M2C_UNK D_6000430;
extern M2C_UNK D_6002848;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80A4D360;
extern M2C_UNK D_80A4D390;

void func_80000000(u8 *arg0, s32 arg1) {
    s16 temp_v1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136E1C(arg1, arg0 + 0x144, &D_6002848, &D_6000430, arg0 + 0x188, arg0 + 0x1CA, 0xB);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, M2C_UNK **, 0xA0) = &D_80A4D390;
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x1F) = 1;
    func_800E1134(arg1, arg0 + 0x244, arg0, &D_80A4D360);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x21E) = (s16) (temp_v1 & 0x7F);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x08000000);
    M2C_FIELD(arg0, s16 *, 0x220) = (s16) ((temp_v1 >> 7) & 0x1F);
    M2C_FIELD(arg0, s16 *, 0x21E) = (s16) (temp_v1 & 0x7F);
    M2C_FIELD(arg0, s16 *, 0x226) = (s16) ((temp_v1 >> 0xC) & 0xF);
    if (M2C_FIELD(arg0, s16 *, 0x21E) == 0x7F) {
        M2C_FIELD(arg0, s16 *, 0x21E) = -1;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x21E) >= 0) && (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x21E)) != 0)) {
        func_800B6490(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x220) == 0x1F) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x21C) = 0;
    func_80A4C794(arg0);
}
