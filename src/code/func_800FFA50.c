// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void IChain_Apply_Vec3f(s32 arg0, void *arg1) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (M2C_FIELD(arg1, u16 *, 0) & 0x7FF) + arg0;
    temp_f0 = (f32) M2C_FIELD(arg1, s16 *, 2);
    M2C_FIELD(temp_v0, f32 *, 8) = temp_f0;
    M2C_FIELD(temp_v0, f32 *, 4) = temp_f0;
    M2C_FIELD(temp_v0, f32 *, 0) = temp_f0;
}
