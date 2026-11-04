// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawSkyboxStars(PlayState* play) {
    Gfx* gfx;
    Gfx* gfxHead;

    if (sSkyboxStarsDList != NULL) {
        OPEN_DISPS(play->state.gfxCtx);

        gfxHead = POLY_OPA_DISP;
        gfx = Gfx_Open(gfxHead);

        gSPDisplayList(sSkyboxStarsDList, gfx);

        Environment_DrawSkyboxStarsImpl(play, &gfx);

        gSPEndDisplayList(gfx++);

        Gfx_Close(gfxHead, gfx);

        POLY_OPA_DISP = gfx;
        sSkyboxStarsDList = NULL;

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
