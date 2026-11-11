#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0556.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800E0160(M2C_UNK);                         /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, s32, M2C_UNK *);      /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BA66CC(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600C240;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BA6F48;
extern M2C_UNK D_80BA847C;
extern M2C_UNK D_80BA84A8;

void func_80000A88(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41900000);
    func_80136ED0(arg1, arg0 + 0x144, &D_600C240, 0, arg0 + 0x280, arg0 + 0x2E0, 0x10);
    M2C_FIELD(arg0, s32 *, 0x36C) = -1;
    func_80BA66CC(arg0, 0);
    func_800E1134(arg1, arg0 + 0x18C, arg0, &D_80BA847C);
    func_800E731C(arg0 + 0xA0, func_800E0160(0x16), &D_80BA84A8);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    M2C_FIELD(arg0, f32 *, 0xFC) = 800.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    func_8013B284(arg0 + 0x340, 0, 7);
    M2C_FIELD(arg0, u16 *, 0x340) = (u16) (M2C_FIELD(arg0, u16 *, 0x340) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x1D8) = 0;
    M2C_FIELD(arg0, s32 *, 0x368) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BA6F48;
}
