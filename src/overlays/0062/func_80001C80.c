// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx *func_80001C80(GraphicsContext *gfxCtx) {
    Gfx *gfxHead = GRAPH_ALLOC(gfxCtx, sizeof(Gfx));
    Gfx *gfx = gfxHead;
    gSPEndDisplayList(gfx++);
    return gfxHead;
}
