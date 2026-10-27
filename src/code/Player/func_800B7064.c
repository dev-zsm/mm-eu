// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_800B7064(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x14C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x148) = 0.0f;
}
