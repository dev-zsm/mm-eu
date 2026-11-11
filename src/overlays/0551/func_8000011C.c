#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0551.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
f32 func_8017A844(f32);                             /* extern */
M2C_UNK func_80B9D71C(u8 *, s32);                 /* extern */
extern M2C_UNK D_600EE20;
extern M2C_UNK D_600EEAC;
extern s32 D_80B9E4CC;
extern M2C_UNK D_80B9E4F0;
extern f32 D_80B9E558;

void func_8000011C(u8 *arg0, s32 arg1) {
    s32 temp_t2;

    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_800E1134(arg1, arg0 + 0x260, arg0, &D_80B9E4F0);
    func_800E1134(arg1, arg0 + 0x2AC, arg0, &D_80B9E4F0);
    func_80136ED0(arg1, arg0 + 0x144, &D_600EE20, &D_600EEAC, arg0 + 0x188, arg0 + 0x1C4, 0xA);
    func_800B6564(arg0, 0x3CA3D70A);
    func_80B9D71C(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    temp_t2 = (s32) func_8017A844(D_80B9E558);
    M2C_FIELD(arg0, s32 *, 0x250) = temp_t2;
    M2C_FIELD(arg0, f32 *, 0x244) = 430.0f;
    D_80B9E4CC = M2C_FIELD(arg0, s32 *, 0x120);
}
