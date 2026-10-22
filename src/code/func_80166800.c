// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801EB7E0;

void Play_DisableMotionBlur(void) {
    M2C_FIELD(D_801EB7E0, s16 *, 0x18A) = 0;
}
