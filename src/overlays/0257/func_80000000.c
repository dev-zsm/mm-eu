#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_6000E88;
extern M2C_UNK D_8098AEB0;
extern M2C_UNK D_8098AEDC;

void func_80000000(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    func_800FF8DC(arg0, &D_8098AEDC);
    temp_a1 = arg0 + 0x144;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_8098AEB0);
    func_800E7BB8(arg0, temp_a1);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s32 *, 0x190) = func_80100304(&D_6000E88);
}
