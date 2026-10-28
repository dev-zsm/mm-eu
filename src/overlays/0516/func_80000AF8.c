// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK func_80B69288(u8 *, s32);                 /* extern */
M2C_UNK func_80B6956C(u8 *, s32);                 /* extern */
extern M2C_UNK D_600B448;
extern M2C_UNK D_80B6A090;
extern M2C_UNK D_80B6A0C8;

void func_80000AF8(u8 *arg0, s32 arg1) {
    u8 *sp24;
    u8 *temp_a1;

    func_800FF8DC(arg0, &D_80B6A0C8);
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    temp_a1 = arg0 + 0x144;
    sp24 = temp_a1;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80B6A090);
    func_800E7BB8(arg0, temp_a1);
    M2C_FIELD(arg0, s32 *, 0x190) = func_80100304(&D_600B448);
    func_800B64E0(arg0, 0xC2C80000);
    func_80B69288(arg0, arg1);
    func_80B6956C(arg0, arg1);
}
