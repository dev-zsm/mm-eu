// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx *func_80000278(GraphicsContext *gfxCtx, s32 a) {
    Gfx *gfxHead = GRAPH_ALLOC(gfxCtx, 2 * sizeof(Gfx));
    Gfx *gfx = gfxHead;
    gDPSetEnvColor(gfx++, 0, 0, 0, a);
    gSPEndDisplayList(gfx++);
    return gfxHead;
}
