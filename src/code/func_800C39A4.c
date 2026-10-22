// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void BgCheck_UnsetContextFlags(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x146C) = (s32) (M2C_FIELD(arg0, s32 *, 0x146C) & ~arg1);
}
