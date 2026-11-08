// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 THA_GetRemaining(struct TwoHeadArena *tha) {
    return M2C_FIELD(tha, s32 *, 0xC) - M2C_FIELD(tha, s32 *, 8);
}
