// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Flags_UnsetClear(struct PlayState *play, s32 roomNumber) {
    M2C_FIELD(play, s32 *, 0x1E6C) = (s32) (M2C_FIELD(play, s32 *, 0x1E6C) & ~(1 << roomNumber));
}
