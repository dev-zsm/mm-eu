// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

void View_SetScissor(Gfx** gfx, s32 ulx, s32 uly, s32 lrx, s32 lry) {
    Gfx* gfxP = *gfx;

    gDPSetScissor(gfxP++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);

    *gfx = gfxP;
}
