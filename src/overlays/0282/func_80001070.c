// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void BgSpdweb_Draw(Actor* thisx, PlayState* play) {
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_XLU_DISP;

    gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);

    if (thisx->params == BGSPDWEB_FF_1) {
        MATRIX_FINALIZE_AND_LOAD(&gfx[1], play->state.gfxCtx);
        gSPDisplayList(&gfx[2], object_spdweb_DL_000060);
    } else {
        Matrix_Translate(0.0f, (thisx->home.pos.y - thisx->world.pos.y) * 10.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(1.0f, ((thisx->home.pos.y - thisx->world.pos.y) + 10.0f) * 0.1f, 1.0f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(&gfx[1], play->state.gfxCtx);
        gSPDisplayList(&gfx[2], object_spdweb_DL_0012F0);
    }

    POLY_XLU_DISP = &gfx[3];

    CLOSE_DISPS(play->state.gfxCtx);
}
