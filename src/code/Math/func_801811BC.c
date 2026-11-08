// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Atan2F(f32, f32);                    /* extern */

f32 Math_Atan2F_XY(f32 x, f32 y) {
    Math_Atan2F(y, x);
}
