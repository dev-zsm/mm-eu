// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Flags_GetClear(struct PlayState *play, s32 roomNumber) {
    return M2C_FIELD(play, s32 *, 0x1E6C) & (1 << roomNumber);
}
