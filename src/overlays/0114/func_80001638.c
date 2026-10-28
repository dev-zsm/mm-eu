// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_808D8BA0(u8 *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808D9470(u8 *);                      /* extern */

void func_80001638(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 5);
    }
    func_800B6564(arg0, 0x3CA3D70A);
    func_808D9470(arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    M2C_FIELD(arg0, f32 *, 0x44C) = 10.0f;
    func_808D8BA0(arg0, arg1, 0, 0, 0);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x44C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x450) = 1.0f;
    func_800FF30C(arg0 + 8, arg0 + 0x24);
    M2C_FIELD(arg0, u16 *, 0x410) = (u16) (M2C_FIELD(arg0, u16 *, 0x410) | 4);
}
