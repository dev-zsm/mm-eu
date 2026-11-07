// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_astr_bombwall.h"

void BgAstrBombwall_Draw(Actor* thixs, PlayState* play) {
    {
        Gfx* opa;

        OPEN_DISPS(play->state.gfxCtx);

        opa = POLY_OPA_DISP;
        gSPDisplayList(&opa[0], gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(&opa[1], play->state.gfxCtx);
        gSPSetGeometryMode(&opa[2], G_LIGHTING_POSITIONAL);
        gSPDisplayList(&opa[3], gAstralObservatoryBombWallDL);
        POLY_OPA_DISP = &opa[4];

        CLOSE_DISPS(play->state.gfxCtx);
    }
    {
        Gfx* xlu;

        OPEN_DISPS(play->state.gfxCtx);

        xlu = POLY_XLU_DISP;
        gSPDisplayList(&xlu[0], gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(&xlu[1], play->state.gfxCtx);
        gSPSetGeometryMode(&xlu[2], G_LIGHTING_POSITIONAL);
        gSPDisplayList(&xlu[3], gAstralObservatoryBombWallCrackDL);
        POLY_XLU_DISP = &xlu[4];

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
