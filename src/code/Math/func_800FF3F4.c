// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Math_Vec3f_Diff(struct Vec3f *l, struct Vec3f *r, struct Vec3f *dest) {
    M2C_FIELD(dest, f32 *, 0) = (f32) (M2C_FIELD(l, f32 *, 0) - M2C_FIELD(r, f32 *, 0));
    M2C_FIELD(dest, f32 *, 4) = (f32) (M2C_FIELD(l, f32 *, 4) - M2C_FIELD(r, f32 *, 4));
    M2C_FIELD(dest, f32 *, 8) = (f32) (M2C_FIELD(l, f32 *, 8) - M2C_FIELD(r, f32 *, 8));
}
