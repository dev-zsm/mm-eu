// FLAGS: -O2 -g0 -mips2
#include "types.h"
void GfxPrint_VPrintf(s32 a, s32 b, s32 *c);
void GfxPrint_Printf(s32 a0, s32 a1, s32 a2, ...) {
    s32 *p = &a1;
    GfxPrint_VPrintf(a0, *p, &a2);
}
