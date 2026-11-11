#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80091B94(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32, f32); /* extern */
extern f32 D_80AAA464;

u8 *func_80000038(u8 *arg0) {
    func_800897D0(arg0, 0x1E0);
    func_80091B94(arg0 + 0x18, 0xC3200000, 0x43200000, 0xC2F00000, 120.0f, -1000.0f, 1000.0f, 1.0f);
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
    M2C_FIELD(arg0, f32 *, 4) = 1.0f;
    M2C_FIELD(arg0, f32 *, 8) = (f32) D_80AAA464;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    return arg0;
}
