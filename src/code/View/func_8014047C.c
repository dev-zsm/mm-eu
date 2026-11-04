// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

s32 View_ApplyTo(View* view, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    GraphicsContext* gfxCtx = view->gfxCtx;
    Viewport* viewport = &view->viewport;
    Mtx* projection;
    Vp* vp;

    vp = GRAPH_ALLOC(gfxCtx, sizeof(Vp));
    View_ViewportToVp(vp, viewport);
    view->vp = *vp;

    View_ClearScissor(view, &gfx);

    gSPViewport(gfx++, vp);

    projection = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
    view->projectionPtr = projection;

    guOrtho(projection, gScreenWidth * -0.5f, gScreenWidth * 0.5f, gScreenHeight * -0.5f, gScreenHeight * 0.5f,
            view->zNear, view->zFar, view->scale);

    view->projection = *projection;

    gSPMatrix(gfx++, projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    *gfxP = gfx;

    return 1;
}
