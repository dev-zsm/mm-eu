// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void BgCheck_Vec3sToVec3f(struct Vec3s *src, struct Vec3f *dest) {
    M2C_FIELD(dest, f32 *, 0) = (f32) M2C_FIELD(src, s16 *, 0);
    M2C_FIELD(dest, f32 *, 4) = (f32) M2C_FIELD(src, s16 *, 2);
    M2C_FIELD(dest, f32 *, 8) = (f32) M2C_FIELD(src, s16 *, 4);
}
