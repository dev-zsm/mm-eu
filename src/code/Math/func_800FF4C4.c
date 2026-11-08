// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Math_Vec3f_ScaleAndStore(struct Vec3f *vec, f32 scale, struct Vec3f *dest) {
    M2C_FIELD(dest, f32 *, 0) = (f32) (M2C_FIELD(vec, f32 *, 0) * scale);
    M2C_FIELD(dest, f32 *, 4) = (f32) (M2C_FIELD(vec, f32 *, 4) * scale);
    M2C_FIELD(dest, f32 *, 8) = (f32) (M2C_FIELD(vec, f32 *, 8) * scale);
}
