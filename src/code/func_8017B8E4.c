// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math3D_Dist1DSq(f32, f32);                    /* extern */

void Math3D_Dist2DSq(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Math3D_Dist1DSq(arg0 - arg2, arg1 - arg3);
}
