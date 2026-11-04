// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/game.h"

void GameState_DrawEnd(GraphicsContext* gfxCtx) {
    Gfx* gfx;
    Gfx* gfxHead;

    OPEN_DISPS(gfxCtx);

    gfx = Gfx_Open(gfxHead = POLY_OPA_DISP);
    gSPDisplayList(OVERLAY_DISP++, gfx);
    gSPEndDisplayList(gfx++);
    Gfx_Close(gfxHead, gfx);

    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(gfxCtx);
}
