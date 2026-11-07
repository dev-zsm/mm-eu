// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_lastday.h"

void EffLastday_Draw(Actor* thisx, PlayState* play) {
    EffLastday* this = (EffLastday*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    switch (EFFLASTDAY_GET_F(thisx)) {
        case EFFLASTDAY_PARAM_1:
        case EFFLASTDAY_PARAM_2:
            break;

        case EFFLASTDAY_PARAM_3:
            EffLastday_SetVtxAlpha(this->alpha);
            break;

        default:
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 170, this->alpha);
            break;
    }
    AnimatedMat_DrawAlphaStep(play, this->matAnim, 1.0f, this->step);
    Gfx_DrawDListXlu(play, this->dList);

    CLOSE_DISPS(play->state.gfxCtx);
}
