// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BBDB50;

void func_80000AD0(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1E0);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s32 *, 0x1E0) = (s32) (temp_v0 - 1);
    }
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BBDB50;
}
