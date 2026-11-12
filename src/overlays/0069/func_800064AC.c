#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137884(u8 *, s32, f32, u8 *);    /* extern */
extern u32 D_80888628[];
extern f32 D_80888A0C;

void func_800064AC(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0x20C) = 6;
    M2C_FIELD(arg0, s32 *, 0x380) = 1;
    func_80137884(arg0 + 0x1A4, M2C_FIELD(D_80888628[M2C_FIELD(arg0, s32 *, 0x150)], s32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x70) * D_80888A0C * 1.5f, arg0);
}
