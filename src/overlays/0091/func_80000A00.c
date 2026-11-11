#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0091.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, s32);                 /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_6005B3C;
extern M2C_UNK D_808AFE88;

void func_80000A00(u8 *arg0, M2C_UNK arg1) {
    func_80137788(arg0 + 0x144, &D_6005B3C, 0x3F800000, 0x40800000, (f32) (func_80134AE8(&D_6005B3C) - 6), 2, 0.0f);
    func_800BE288(arg0, arg0 + 0x2E8);
    M2C_FIELD(arg0, f32 *, 0x70) = 6.0f;
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, func_80134AE8(&D_6005B3C) - 0xA);
    func_800B8C4C(arg0, 0x3847);
    M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F9) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x234) = 0xFF;
    M2C_FIELD(arg0, M2C_UNK **, 0x230) = &D_808AFE88;
}
