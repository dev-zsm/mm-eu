// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_shrink_window.h"

void ShrinkWindow_Draw(GraphicsContext* gfxCtx) {
    Gfx* gfx;
    s8 letterboxSize = sShrinkWindowPtr->letterboxSize;
    s8 pillarboxSize = sShrinkWindowPtr->pillarboxSize;

    if (letterboxSize > 0) {
        OPEN_DISPS(gfxCtx);

        gfx = OVERLAY_DISP;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfx++, 0, 0, gScreenWidth - 1, letterboxSize - 1);
        gDPFillRectangle(gfx++, 0, gScreenHeight - letterboxSize, gScreenWidth - 1, gScreenHeight - 1);

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 0);
        gDPFillRectangle(gfx++, 0, letterboxSize, gScreenWidth, letterboxSize + 1);
        gDPFillRectangle(gfx++, 0, gScreenHeight - letterboxSize - 1, gScreenWidth, gScreenHeight - letterboxSize);

        gDPPipeSync(gfx++);
        OVERLAY_DISP = gfx++;

        CLOSE_DISPS(gfxCtx);
    }

    if (pillarboxSize > 0) {
        OPEN_DISPS(gfxCtx);

        gfx = OVERLAY_DISP;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));

        gDPFillRectangle(gfx++, 0, 0, pillarboxSize - 1, gScreenHeight - 1);
        gDPFillRectangle(gfx++, gScreenWidth - pillarboxSize, 0, gScreenWidth - 1, gScreenHeight - 1);

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 0);

        gDPFillRectangle(gfx++, pillarboxSize, 0, pillarboxSize + 2, gScreenHeight);
        gDPFillRectangle(gfx++, gScreenWidth - pillarboxSize - 2, 0, gScreenWidth - pillarboxSize, gScreenHeight);

        gDPPipeSync(gfx++);
        OVERLAY_DISP = gfx++;

        CLOSE_DISPS(gfxCtx);
    }
}
