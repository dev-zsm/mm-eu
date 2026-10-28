// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, u16);                 /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600CDE0;
extern M2C_UNK D_80999998;

void func_80002B0C(u8 *arg0, M2C_UNK arg1) {
    func_80137934(arg0 + 0x194, &D_600CDE0, 0xC1C80000, arg0);
    func_800B8C4C(arg0, M2C_FIELD(arg0, u16 *, 0x6B6));
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80999998;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x23;
}
