// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_spot.h"

void BgOpenSpot_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    BgOpenSpot* this = (BgOpenSpot*)thisx;

    AnimatedMat_Draw(play, this->texScrolls);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_BAYER);
    gSPDisplayList(POLY_XLU_DISP++, gSpotlightLeftDL);
    gSPDisplayList(POLY_XLU_DISP++, gSpotlightRightDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
