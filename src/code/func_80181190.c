// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80180F74(f32, f32);                    /* extern */

void Math_Atan2S_XY(f32 arg0, f32 arg1) {
    func_80180F74(arg1, arg0);
}
