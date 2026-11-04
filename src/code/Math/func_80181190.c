// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_Atan2S(f32, f32);                    /* extern */

void Math_Atan2S_XY(f32 arg0, f32 arg1) {
    Math_Atan2S(arg1, arg0);
}
