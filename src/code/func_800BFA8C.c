// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void BgCheck_Vec3sToVec3f(void *arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(arg0, s16 *, 0);
    M2C_FIELD(arg1, f32 *, 4) = (f32) M2C_FIELD(arg0, s16 *, 2);
    M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(arg0, s16 *, 4);
}
