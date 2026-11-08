// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

union Gfx * Gfx_Close(union Gfx *gfx, union Gfx *dst) {
    M2C_FIELD(gfx, s32 *, 0) = 0xDE010000;
    M2C_FIELD(gfx, s32 *, 4) = dst;
    return dst;
}
