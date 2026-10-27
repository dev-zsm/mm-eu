// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 Math_Vec3f_DistXZ(void *, void *);                  /* extern */
M2C_UNK Math_Atan2S_XY(f32, f32);                    /* extern */

void Math_Vec3f_Pitch(void *arg0, void *arg1) {
    Math_Atan2S_XY(Math_Vec3f_DistXZ(arg0, arg1), M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(arg1, f32 *, 4));
}
