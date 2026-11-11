#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE350(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_808BF780;
extern f32 D_808C0500;

void func_80000D6C(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, u8 *, 0x395) = (u8) (M2C_FIELD(arg0, u8 *, 0x395) & 0xFFFE);
    func_800B8C4C(arg0, 0x38E3);
    func_800BE350(arg0, arg0 + 0x384, 0);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0xB9);
    if (temp_v0 == 5) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
        M2C_FIELD(arg0, s8 *, 0x24F) = 0x20;
        M2C_FIELD(arg0, f32 *, 0x25C) = 2.0f;
        M2C_FIELD(arg0, f32 *, 0x260) = (f32) D_808C0500;
    } else if (temp_v0 == 1) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x14);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else if (temp_v0 == 0xE) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else {
        func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x14);
        M2C_FIELD(arg0, f32 *, 0x70) = 7.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808BF780;
}
