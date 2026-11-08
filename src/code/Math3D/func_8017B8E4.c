// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math3D_Dist1DSq(f32, f32);                    /* extern */

f32 Math3D_Dist2DSq(f32 x0, f32 y0, f32 x1, f32 y1) {
    Math3D_Dist1DSq(x0 - x1, y0 - y1);
}
