// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AF26FC();                            /* extern */
extern M2C_UNK D_80AEF5F4;

void func_800055EC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x19C) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x160) = 0.5f;
    func_80AF26FC();
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEF5F4;
}
