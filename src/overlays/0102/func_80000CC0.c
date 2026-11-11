#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE2EC(u8 *, u8 *);              /* extern */
extern M2C_UNK D_808C21FC;
extern f32 D_808C2F20;

void func_80000CC0(u8 *arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, u8 *, 0x305) = (u8) (M2C_FIELD(arg0, u8 *, 0x305) & 0xFFFE);
    func_800B8C4C(arg0, 0x38E3);
    func_800BE2EC(arg0, arg0 + 0x2F4);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0xB9);
    if (temp_v0 == 5) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
        M2C_FIELD(arg0, s8 *, 0x24D) = 0x20;
        M2C_FIELD(arg0, f32 *, 0x26C) = 2.0f;
        M2C_FIELD(arg0, f32 *, 0x270) = (f32) D_808C2F20;
    } else if (temp_v0 == 1) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x14);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else if (temp_v0 == 0xE) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else {
        func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x14);
        M2C_FIELD(arg0, f32 *, 0x70) = 7.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808C21FC;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
}
