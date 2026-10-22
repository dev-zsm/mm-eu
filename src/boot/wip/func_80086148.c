// FLAGS: -O2 -g3 -mips2
#include "types.h"

void GfxPrint_VPrintf(s32 a, s32 b, s32 *c);

/* only missing: sw a1,36(sp) spill */
void GfxPrint_Printf(s32 a0, s32 a1, s32 a2, ...) {
    GfxPrint_VPrintf(a0, a1, &a2);
}
