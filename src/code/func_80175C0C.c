// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Gfx_Close(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0xDE010000;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return arg1;
}
