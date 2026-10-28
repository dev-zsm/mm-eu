// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
extern M2C_UNK D_808AD594;

void func_800014E0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x30) = 0x4000;
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 4);
    M2C_FIELD(arg0, s16 *, 0x1DC) = 0x19;
    func_800FF30C(arg0 + 0x1F4, arg0 + 0x24);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808AD594;
}
