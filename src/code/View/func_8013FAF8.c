// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

s32 View_ApplyPerspective(View* view) {
    f32 aspect;
    s32 width;
    s32 height;
    Vp* vp;
    Mtx* projection;
    Mtx* viewing;
    GraphicsContext* gfxCtx = view->gfxCtx;

    OPEN_DISPS(gfxCtx);

    
    vp = GRAPH_ALLOC(gfxCtx, sizeof(Vp));
    View_ViewportToVp(vp, &view->viewport);
    view->vp = *vp;

    View_ApplyLetterbox(view);

    gSPViewport(POLY_OPA_DISP++, vp);
    gSPViewport(POLY_XLU_DISP++, vp);

    
    projection = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
    view->projectionPtr = projection;

    width = view->viewport.rightX - view->viewport.leftX;
    height = view->viewport.bottomY - view->viewport.topY;
    aspect = (f32)width / (f32)height;

    guPerspective(projection, &view->perspNorm, view->fovy, aspect, view->zNear, view->zFar, view->scale);
    view->projection = *projection;

    View_StepDistortion(view, projection);

    gSPPerspNormalize(POLY_OPA_DISP++, view->perspNorm);
    gSPMatrix(POLY_OPA_DISP++, projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(POLY_XLU_DISP++, view->perspNorm);
    gSPMatrix(POLY_XLU_DISP++, projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    
    viewing = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
    view->viewingPtr = viewing;

    if ((view->eye.x == view->at.x) && (view->eye.y == view->at.y) && (view->eye.z == view->at.z)) {
        view->eye.z += 2.0f;
    }

    guLookAt(viewing, view->eye.x, view->eye.y, view->eye.z, view->at.x, view->at.y, view->at.z, view->up.x, view->up.y,
             view->up.z);

    view->viewing = *viewing;

    gSPMatrix(POLY_OPA_DISP++, viewing, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(POLY_XLU_DISP++, viewing, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    CLOSE_DISPS(gfxCtx);

    return 1;
}
