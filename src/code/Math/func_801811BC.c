// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Atan2F(f32, f32);                    /* extern */

void Math_Atan2F_XY(f32 arg0, f32 arg1) {
    Math_Atan2F(arg1, arg0);
}
