// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx* Gfx_PrimColor(GraphicsContext* gfxCtx, s32 lodfrac, s32 r, s32 g, s32 b, s32 a) {
    Gfx* gfx = GRAPH_ALLOC(gfxCtx, 2 * sizeof(Gfx));

    gDPSetPrimColor(&gfx[0], 0, lodfrac, r, g, b, a);
    gSPEndDisplayList(&gfx[1]);

    return gfx;
}
