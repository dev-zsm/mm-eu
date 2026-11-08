// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_Atan2S(f32, f32);                    /* extern */

s16 Math_Atan2S_XY(f32 x, f32 y) {
    Math_Atan2S(y, x);
}
