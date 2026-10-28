// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80BAA380;
extern M2C_UNK D_80BAB5A8;

void func_80000650(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x32C) = 0;
    func_800B8C4C(arg0, 0x3873);
    func_800B8C4C(arg0, 0x38EC);
    func_800BD9E0(arg0 + 0x1F0, &D_80BAB5A8, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_80BAA380;
}
