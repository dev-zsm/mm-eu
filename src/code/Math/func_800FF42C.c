// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Math_Vec3s_DiffToVec3f(struct Vec3f *dest, struct Vec3s *l, struct Vec3s *r) {
    M2C_FIELD(dest, f32 *, 0) = (f32) (M2C_FIELD(l, s16 *, 0) - M2C_FIELD(r, s16 *, 0));
    M2C_FIELD(dest, f32 *, 4) = (f32) (M2C_FIELD(l, s16 *, 2) - M2C_FIELD(r, s16 *, 2));
    M2C_FIELD(dest, f32 *, 8) = (f32) (M2C_FIELD(l, s16 *, 4) - M2C_FIELD(r, s16 *, 4));
}
