// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Player_SetBButtonAmmo(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1887C) = (s8) (arg1 + 1);
    return 1;
}
