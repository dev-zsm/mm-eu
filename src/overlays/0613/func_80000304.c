#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0613.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, M2C_UNK); /* extern */
extern f32 D_80BE2DC0;
extern f32 D_80BE2DC4;

s32 func_80000304(u8 *arg0) {
    s32 sp24;
    f32 temp_f0;

    sp24 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x248) == 0) {
        func_800B8C4C(arg0, 0x28D1);
        M2C_FIELD(arg0, s32 *, 0x248) = 1;
    }
    func_800FFBF8(arg0 + 0x58, 0, 0x3E570A3D, 0x3E99999A);
    if (M2C_FIELD(arg0, f32 *, 0x58) < D_80BE2DC0) {
        M2C_FIELD(arg0, u16 *, 0x234) = (u16) (M2C_FIELD(arg0, u16 *, 0x234) & 0xFEFF);
        M2C_FIELD(arg0, f32 *, 0x58) = 0.0f;
        sp24 = 1;
    }
    temp_f0 = (M2C_FIELD(arg0, f32 *, 0x58) / D_80BE2DC4) * 4.0f;
    M2C_FIELD(arg0, f32 *, 0x23C) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + temp_f0);
    func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x58));
    return sp24;
}
