// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
f32 func_800FFAD8(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80A46FC0(u8 *);                      /* extern */
M2C_UNK func_80A47A50(u8 *, s32);                 /* extern */
extern f32 D_80A48C84;
extern f32 D_80A48C88;

void func_800009B4(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    if (func_800FFAD8(arg0 + 0x1F0, 0x3F800000, 0x3D4CCCCD, 0x3CF5C28F, D_80A48C84) == 0.0f) {
        func_80A46FC0(arg0);
    }
    func_80A47A50(arg0, arg1);
    func_800B8D94(arg0, 0x214A);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x1F0) * D_80A48C88;
    M2C_FIELD(arg0, f32 *, 0x1F8) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x1F4) = temp_f0;
}
