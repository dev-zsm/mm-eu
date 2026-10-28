// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A9A9A4();                            /* extern */
M2C_UNK func_80A9AC9C();                            /* extern */
extern M2C_UNK D_80A9C234;

void func_80002894(u8 *arg0) {
    if ((M2C_FIELD(arg0, f32 *, 0x9C) > -10.0f) && (M2C_FIELD(arg0, f32 *, 0x98) < 160.0f)) {
        func_80A9A9A4();
        M2C_FIELD(arg0, s32 *, 0x3C0) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9C234;
        return;
    }
    func_80A9AC9C();
}
