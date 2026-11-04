// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx* Gfx_TexScroll(GraphicsContext* gfxCtx, u32 x, u32 y, s32 width, s32 height) {
    Gfx* gfx = GRAPH_ALLOC(gfxCtx, 3 * sizeof(Gfx));

    x %= 2048;
    y %= 2048;

    gDPTileSync(&gfx[0]);
    gDPSetTileSize(&gfx[1], 0, x, y, (x + ((width - 1) << 2)), (y + ((height - 1) << 2)));
    gSPEndDisplayList(&gfx[2]);

    return gfx;
}
