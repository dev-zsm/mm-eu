// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

void View_ClearScissor(View* view, Gfx** gfx) {
    Gfx* gfxP = *gfx;
    s32 ulx = view->viewport.leftX;
    s32 uly = view->viewport.topY;
    s32 lrx = view->viewport.rightX;
    s32 lry = view->viewport.bottomY;

    gDPPipeSync(gfxP++);
    View_SetScissor(&gfxP, ulx, uly, lrx, lry);

    *gfx = gfxP;
}
