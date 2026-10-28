// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80906F20(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_80906FCC;
extern M2C_UNK D_80908CE0;

void func_8000000C(u8 *arg0, M2C_UNK arg1) {
    func_800FF8DC(arg0, &D_80908CE0);
    M2C_FIELD(arg0, s16 *, 0x144) = 0;
    M2C_FIELD(arg0, f32 *, 0x158) = 1.0f;
    func_80906F20(arg0, &D_80906FCC);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, s8 *, 0x148) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x146) = 0;
    M2C_FIELD(arg0, f32 *, 0x15C) = 0.0f;
}
