// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801EB7E0;
extern s8 D_801EE68D;

void Play_DestroyMotionBlur(void) {
    M2C_FIELD(D_801EB7E0, s16 *, 0x18A) = 0;
    M2C_FIELD(D_801EB7E0, s16 *, 0x18E) = 0;
    D_801EE68D = 0;
}
