// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/game.h"

void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx) {
    Gfx* gfx;
    Gfx* gfxHead;

    OPEN_DISPS(gfxCtx);

    gfx = Gfx_Open(gfxHead = POLY_OPA_DISP);
    gSPDisplayList(OVERLAY_DISP++, gfx);

    if ((R_FB_FILTER_TYPE != 0) && (R_FB_FILTER_ENV_COLOR(3) == 0)) {
        GameState_SetFBFilter(&gfx, gfxCtx->zbuffer);
    }

    if (R_ENABLE_ARENA_DBG < 0) {
        R_ENABLE_ARENA_DBG = 0;
    }

    gSPEndDisplayList(gfx++);
    Gfx_Close(gfxHead, gfx);
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(gfxCtx);

    Debug_DrawText(gfxCtx);

    if (R_ENABLE_ARENA_DBG != 0) {
        SpeedMeter_DrawTimeEntries(&sGameSpeedMeter, gfxCtx);
        SpeedMeter_DrawAllocEntries(&sGameSpeedMeter, gfxCtx, gameState);
    }
}
