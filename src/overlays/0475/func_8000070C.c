#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0475.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
s32 func_800E0160(M2C_UNK);                         /* extern */
M2C_UNK func_800E1134(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, s32, M2C_UNK *);      /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8013C01C(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6001A80;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80B10AC8;
extern M2C_UNK D_80B111E8;
extern M2C_UNK D_80B11214;
extern M2C_UNK D_80B11220;

void func_8000070C(u8 *arg0, s32 arg1) {
    s32 sp30;
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41900000);
    temp_a1 = arg0 + 0x144;
    sp30 = temp_a1;
    func_80136ED0(arg1, temp_a1, &D_6001A80, 0, arg0 + 0x1E4, arg0 + 0x1F6, 3);
    func_800E1134(arg1, arg0 + 0x18C, arg0, &D_80B111E8);
    func_800E731C(arg0 + 0xA0, func_800E0160(0x16), &D_80B11214);
    func_8013B284(arg0 + 0x208, 3, 7);
    func_8013C01C(sp30, &D_80B11220, 0);
    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    func_800B6564(arg0, 0x3CA3D70A);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B10AC8;
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
}
