// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_60000F8;
extern M2C_UNK D_808ACF60;

void func_80000ECC(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60000F8);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x3848);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808ACF60;
}
