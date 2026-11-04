// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_cheap_proc.h"

void Gfx_DrawDListOpa(PlayState* play, Gfx* dList) {
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_OPA_DISP;

    gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);
    MATRIX_FINALIZE_AND_LOAD(&gfx[1], play->state.gfxCtx);
    gSPDisplayList(&gfx[2], dList);

    POLY_OPA_DISP = &gfx[3];

    CLOSE_DISPS(play->state.gfxCtx);
}
