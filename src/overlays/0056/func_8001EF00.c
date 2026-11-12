#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */
s32 func_80136480(s32, u8 *);                     /* extern */
M2C_UNK func_8082D1EC(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_808331C8(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32, s32); /* extern */
M2C_UNK func_808361EC(s32, u8 *, M2C_UNK);        /* extern */
extern M2C_UNK D_400DE60;

void func_8001EF00(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x20);
    if (func_80136480(arg1, arg0 + 0x240) != 0) {
        func_8082D1EC(arg1, arg0, &D_400DE60);
    }
    func_800FEE3C(arg0 + 0xAD0, 0, 0x3D4CCCCD);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        if (M2C_FIELD(arg0, s16 *, 0xB6A) >= 0x190) {
            M2C_FIELD(arg0, s8 *, 0xB8) = 0x10;
            func_808331C8(arg1, arg0, 1, 0x40800000, 5.0f, (s32) M2C_FIELD(arg0, s16 *, 0xBE), 0x14);
            return;
        }
        func_808361EC(arg1, arg0, 0x40800000);
    }
}
