// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800CB9E0(void *arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x114);
    if ((temp_f0 != M2C_FIELD(arg0, f32 *, 0x104)) && (temp_f0 < arg1) && (arg2 < temp_f0)) {
        return 1;
    }
    return 0;
}
