// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Flags_UnsetClear(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1E6C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E6C) & ~(1 << arg1));
}
