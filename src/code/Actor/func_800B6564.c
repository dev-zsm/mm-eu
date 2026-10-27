// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Actor_SetScale(void *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x60) = arg1;
    M2C_FIELD(arg0, f32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, f32 *, 0x58) = arg1;
}
