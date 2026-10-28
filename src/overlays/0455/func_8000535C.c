// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AEF368;

void func_8000535C(u8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1B4) == 1) {
        M2C_FIELD(arg0, s16 *, 0x19E) = (s16) (M2C_FIELD(arg0, s16 *, 0x19E) - 0x4000);
    } else {
        M2C_FIELD(arg0, s16 *, 0x19E) = (s16) (M2C_FIELD(arg0, s16 *, 0x19E) + 0x4000);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEF368;
    M2C_FIELD(arg0, f32 *, 0x70) = 15.0f;
}
