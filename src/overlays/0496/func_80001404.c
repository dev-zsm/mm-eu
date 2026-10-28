// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, u8 *);              /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6000454;
extern M2C_UNK D_80B47798;

void func_80001404(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6000454, 0xC0C00000);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x10);
    M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BD) & 0xFFFE);
    func_800BE288(arg0, arg0 + 0x2AC);
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B47798;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
}
