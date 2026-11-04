// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

s32 View_ApplyOrthoToOverlay(View* view) {
    Vp* vp;
    Mtx* projection;
    GraphicsContext* gfxCtx;

    gfxCtx = view->gfxCtx;

    OPEN_DISPS(gfxCtx);

    vp = GRAPH_ALLOC(gfxCtx, sizeof(Vp));
    View_ViewportToVp(vp, &view->viewport);
    view->vp = *vp;

    gDPPipeSync(OVERLAY_DISP++);
    {
        Gfx* overlay;
        s32 pad;

        overlay = OVERLAY_DISP;
        View_SetScissor(&overlay, view->viewport.leftX, view->viewport.topY, view->viewport.rightX,
                        view->viewport.bottomY);
        OVERLAY_DISP = overlay;
    }

    gSPViewport(OVERLAY_DISP++, vp);
    projection = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
    view->projectionPtr = projection;

    guOrtho(projection, gScreenWidth * -0.5f, gScreenWidth * 0.5f, gScreenHeight * -0.5f, gScreenHeight * 0.5f,
            view->zNear, view->zFar, view->scale);
    view->projection = *projection;

    gSPMatrix(OVERLAY_DISP++, projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    CLOSE_DISPS(gfxCtx);
    return 1;
}
