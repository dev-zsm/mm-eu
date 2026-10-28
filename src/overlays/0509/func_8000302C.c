// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5DB20(u8 *, u8 *);              /* extern */
M2C_UNK func_80B5DB5C(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80B5DB68(u8 *, u8 *);              /* extern */
M2C_UNK func_80B5DBB8(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80B5DBEC(u8 *, u8 *);              /* extern */
M2C_UNK func_80B5FEA8(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_80B5F334;

void func_8000302C(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(arg0, s32 *, 0x4DC) = 0;
    M2C_FIELD(arg0, s32 *, 0x4E0) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xA6C) & ~0x20);
    func_80B5DB68(arg0, arg1);
    func_80B5DBB8(arg0, arg1, 0x7FFF);
    func_80B5DBEC(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x2F4) = (s32) (M2C_FIELD(arg0, s32 *, 0x2F4) | 0x10);
    func_80B5DB20(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x2F4) = (s32) (M2C_FIELD(arg0, s32 *, 0x2F4) | 4);
    func_80B5FEA8(arg0, arg1, 1);
    func_80B5DB5C(arg0, &D_80B5F334);
}
