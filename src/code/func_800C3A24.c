// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 BgCheck_PosInStaticBoundingBox(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;

    temp_f0 = M2C_FIELD(arg1, f32 *, 0);
    if ((temp_f0 < (M2C_FIELD(arg0, f32 *, 4) - 50.0f)) || ((M2C_FIELD(arg0, f32 *, 0x10) + 50.0f) < temp_f0) || (temp_f0_2 = M2C_FIELD(arg1, f32 *, 4), (temp_f0_2 < (M2C_FIELD(arg0, f32 *, 8) - 50.0f))) || ((M2C_FIELD(arg0, f32 *, 0x14) + 50.0f) < temp_f0_2) || (temp_f0_3 = M2C_FIELD(arg1, f32 *, 8), (temp_f0_3 < (M2C_FIELD(arg0, f32 *, 0xC) - 50.0f))) || ((M2C_FIELD(arg0, f32 *, 0x18) + 50.0f) < temp_f0_3)) {
        return 0;
    }
    return 1;
}
