// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

f32 Math_Vec3f_DiffY(struct Vec3f *a, struct Vec3f *b) {
    return M2C_FIELD(b, f32 *, 4) - M2C_FIELD(a, f32 *, 4);
}
