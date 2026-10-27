// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Animation_SetMorph(s32 arg0, void *arg1, f32 arg2) {
    M2C_FIELD(arg1, f32 *, 0x28) = 1.0f;
    M2C_FIELD(arg1, f32 *, 0x2C) = (f32) (1.0f / arg2);
}
