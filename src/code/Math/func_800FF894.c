// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 Math_Vec3f_DistXZ(void *, void *);                  /* extern */
M2C_UNK Math_Atan2S_XY(f32, f32);                    /* extern */

s16 Math_Vec3f_Pitch(struct Vec3f *a, struct Vec3f *b) {
    Math_Atan2S_XY(Math_Vec3f_DistXZ(a, b), M2C_FIELD(a, f32 *, 4) - M2C_FIELD(b, f32 *, 4));
}
