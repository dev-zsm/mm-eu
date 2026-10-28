// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80AE3FB8;
extern M2C_UNK D_80AE5F30;

void func_8000098C(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80AE5F30, 7);
    func_800B8C4C(arg0, 0x38E6);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AE3FB8;
    M2C_FIELD(arg0, f32 *, 0x70) = -2.0f;
}
