// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_debug_mode.h"

void Debug_DrawText(GraphicsContext* gfxCtx) {
    Gfx* gfx;
    Gfx* gfxHead;
    GfxPrint printer;

    if (THGA_GetRemaining(&gfxCtx->polyOpa) < 0x2800) {
        PRINTF("ディスプレイリスト領域に余裕がないのでデバッグモードの表示を見合わせます\n",
               "There is insufficient space in the display list area, so the debug mode display will be suspended.\n");
        return;
    }

    GfxPrint_Init(&printer);

    OPEN_DISPS(gfxCtx);

    gfxHead = POLY_OPA_DISP;
    gfx = Gfx_Open(gfxHead);
    gSPDisplayList(DEBUG_DISP++, gfx);

    GfxPrint_Open(&printer, gfx);

    if (sDebugTextDrawFlags & DEBUG_TEXT_DRAW_CAM_TEXT) {
        DebugCamera_DrawScreenText(&printer);
    }
    sDebugCamTextEntryCount = 0;

    if (sDebugTextDrawFlags & DEBUG_TEXT_DRAW_TEXT) {
        Debug_DrawScreenText(&printer);
    }

    gfx = GfxPrint_Close(&printer);
    gSPEndDisplayList(gfx++);
    Gfx_Close(gfxHead, gfx);
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(gfxCtx);

    GfxPrint_Destroy(&printer);
}
