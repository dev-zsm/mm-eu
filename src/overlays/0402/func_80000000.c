// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80AAA460;

void func_80000000(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xC);
    if ((temp_v0 == 1) || (temp_v0 == 2)) {
        M2C_FIELD(arg0, f32 *, 4) = 1.0f;
        return;
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) D_80AAA460;
}
