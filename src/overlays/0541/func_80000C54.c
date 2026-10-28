// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80B8AE50;
extern M2C_UNK D_80B8CE60;

void func_80000C54(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80B8CE60, 7);
    func_800B8C4C(arg0, 0x38E6);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B8AE50;
    M2C_FIELD(arg0, f32 *, 0x70) = -2.0f;
}
