#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(u8 *, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_80C021B0(u8 *, M2C_UNK);             /* extern */
s32 func_80C0252C(u8 *);                          /* extern */
extern M2C_UNK D_6009E70;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80C0259C;
extern M2C_UNK D_80C026CC;

void func_8000052C(u8 *arg0, u8 *arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136ED0(arg1, arg0 + 0x144, &D_6009E70, 0, arg0 + 0x1B0, arg0 + 0x216, 0x11);
    M2C_FIELD(arg0, s32 *, 0x294) = -1;
    func_80C021B0(arg0, 0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, u16 *, 0x27C) = (u16) (M2C_FIELD(arg0, u16 *, 0x27C) | 1);
    if ((M2C_FIELD(arg1, s16 *, 0xA4) == 0x61) && (M2C_FIELD(arg1, u8 *, 0x18B48) == 4)) {
        M2C_FIELD(arg0, s32 *, 0x280) = func_80C0252C(arg1);
        func_80C021B0(arg0, 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80C026CC;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80C0259C;
}
