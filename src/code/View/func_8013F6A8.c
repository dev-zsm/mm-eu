// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

void View_ApplyLetterbox(View* view) {
    s32 letterboxY;
    s32 letterboxX;
    s32 pad1;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    OPEN_DISPS(view->gfxCtx);

    letterboxY = ShrinkWindow_Letterbox_GetSize();

    letterboxX = -1; 

    if (letterboxX < 0) {
        letterboxX = 0;
    }
    if (letterboxX > (SCREEN_WIDTH / 2)) {
        letterboxX = SCREEN_WIDTH / 2;
    }

    if (letterboxY < 0) {
        letterboxY = 0;
    } else if (letterboxY > (SCREEN_HEIGHT / 2)) {
        letterboxY = SCREEN_HEIGHT / 2;
    }

    ulx = view->viewport.leftX + letterboxX;
    uly = view->viewport.topY + letterboxY;
    lrx = view->viewport.rightX - letterboxX;
    lry = view->viewport.bottomY - letterboxY;

    gDPPipeSync(POLY_OPA_DISP++);
    {
        s32 pad2;
        Gfx* polyOpa;

        polyOpa = POLY_OPA_DISP;
        View_SetScissor(&polyOpa, ulx, uly, lrx, lry);
        POLY_OPA_DISP = polyOpa;
    }

    gDPPipeSync(POLY_XLU_DISP++);
    {
        Gfx* polyXlu;
        s32 pad3;

        polyXlu = POLY_XLU_DISP;
        View_SetScissor(&polyXlu, ulx, uly, lrx, lry);
        POLY_XLU_DISP = polyXlu;
    }

    CLOSE_DISPS(view->gfxCtx);
}
