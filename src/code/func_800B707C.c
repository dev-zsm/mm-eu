// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_800B707C(void *arg0, f32 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x150) = arg2;
    M2C_FIELD(arg0, f32 *, 0x148) = (f32) (M2C_FIELD(arg0, f32 *, 0x148) + arg1);
}
