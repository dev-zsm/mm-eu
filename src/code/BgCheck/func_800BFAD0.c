// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void BgCheck_Vec3fToVec3s(struct Vec3s *dest, struct Vec3f *src) {
    M2C_FIELD(dest, s16 *, 0) = (s16) (s32) M2C_FIELD(src, f32 *, 0);
    M2C_FIELD(dest, s16 *, 2) = (s16) (s32) M2C_FIELD(src, f32 *, 4);
    M2C_FIELD(dest, s16 *, 4) = (s16) (s32) M2C_FIELD(src, f32 *, 8);
}
