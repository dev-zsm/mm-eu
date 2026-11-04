// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_footmark.h"

void EffFootmark_Draw(PlayState* play) {
    EffFootmark* footmark;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL44_Xlu(play->state.gfxCtx);

    gSPDisplayList(POLY_XLU_DISP++, gEffFootprintMaterialDL);

    for (footmark = play->footprintInfo, i = 0; i < ARRAY_COUNT(play->footprintInfo); i++, footmark++) {
        if (footmark->actor != NULL) {
            Matrix_Put(&footmark->mf);
            Matrix_Scale(footmark->size * (1.0f / 0x100) * 0.7f, 1, footmark->size * (1.0f / 0x100), MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, footmark->red, footmark->green, footmark->blue,
                            footmark->alpha >> 8);

            gSPDisplayList(POLY_XLU_DISP++, gEffFootprintModelDL);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
