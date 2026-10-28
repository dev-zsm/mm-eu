// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
s32 func_800FEE3C(u8 *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_80A07ECC(u8 *, f32);                 /* extern */
M2C_UNK func_80A080CC(s32, u8 *, f32, M2C_UNK, s32); /* extern */
M2C_UNK func_80A08404(u8 *, s32);                 /* extern */
M2C_UNK func_80A0A6A8(u8 *);                      /* extern */
extern f32 D_80A0BD8C;
extern f32 D_80A0BD90;
extern f32 D_80A0BD94;

void func_800027DC(u8 *arg0, s32 arg1) {
    s16 temp_v1;

    func_80A08404(arg0, arg0 + 8);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x2A0);
    if (temp_v1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2A0) = (s16) (temp_v1 - 1);
        return;
    }
    if (func_800FEE3C(arg0 + 0x58, 0x3DCCCCCD, 0x3CA3D70A) != 0) {
        func_800B6564(arg0, 0.1f);
        if (M2C_FIELD(arg0, s16 *, 0x1C) & 1) {
            M2C_FIELD(arg0, f32 *, 0x2B4) = (f32) D_80A0BD8C;
        }
        func_80A0A6A8(arg0);
    } else {
        func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x58));
        M2C_FIELD(arg0, s16 *, 0x2A0) = 2;
    }
    func_80A07ECC(arg0, M2C_FIELD(arg0, f32 *, 0x58));
    if (M2C_FIELD(arg0, s32 *, 4) & 0x40) {
        func_80A080CC(arg1, arg0 + 0x24, (M2C_FIELD(arg0, f32 *, 0x58) + D_80A0BD90) * D_80A0BD94, 0x3F800000, 3);
    }
}
