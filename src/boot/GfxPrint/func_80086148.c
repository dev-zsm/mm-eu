// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

s32 GfxPrint_Printf(GfxPrint *this, const char *fmt, ...) {
    /* the first variadic word sits in the home slot right after fmt */
    return GfxPrint_VPrintf(this, fmt, (va_list)&fmt + 4);
}
