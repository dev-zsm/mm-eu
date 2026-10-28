// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, u8 *, s32, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80992908(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80993E50;

void func_80001784(u8 *arg0, s32 arg1) {
    func_80992908(arg0, 5);
    M2C_FIELD(arg0, s16 *, 0x27C) = 6;
    func_800BBB30(arg1, arg0, arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0xCC), 1, 8.0f, 0x1F4, 0xA, 1);
    func_800FFC68(arg0 + 0x70, 0x3E99999A, 0x40400000);
    M2C_FIELD(arg0, s8 *, 0x34E) = 0;
    func_800B8C4C(arg0, 0x1818);
    M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80993E50;
}
