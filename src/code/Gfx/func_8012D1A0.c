// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx* Gfx_TwoTexScrollEnvColor(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2,
                              u32 x2, u32 y2, s32 width2, s32 height2, s32 r, s32 g, s32 b, s32 a) {
    Gfx* gfx = GRAPH_ALLOC(gfxCtx, 6 * sizeof(Gfx));

    x1 %= 2048;
    y1 %= 2048;
    x2 %= 2048;
    y2 %= 2048;

    gDPTileSync(&gfx[0]);
    gDPSetTileSize(&gfx[1], tile1, x1, y1, (x1 + ((width1 - 1) << 2)), (y1 + ((height1 - 1) << 2)));
    gDPTileSync(&gfx[2]);
    gDPSetTileSize(&gfx[3], tile2, x2, y2, (x2 + ((width2 - 1) << 2)), (y2 + ((height2 - 1) << 2)));
    gDPSetEnvColor(&gfx[4], r, g, b, a);
    gSPEndDisplayList(&gfx[5]);

    return gfx;
}
