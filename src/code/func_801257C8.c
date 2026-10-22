// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_801257C8(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0) = 0.0f;
    M2C_FIELD(arg0, f32 *, 4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 8) = 0.0f;
    M2C_FIELD(arg1, s16 *, 0) = 0;
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = 0;
}
