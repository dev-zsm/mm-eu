// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIkanaMirror* this = (BgIkanaMirror*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gStoneTowerTempleMirrorDL);

    if (this->lightAbsorptionAlpha > 0) {
        AnimatedMat_Draw(play, this->lightAbsorptionTexScroll);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, this->lightAbsorptionAlpha);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gStoneTowerTempleMirrorLightAbsorptionDL);
    }

    if (this->lightEmissionAlpha > 0) {
        f32 alphaFraction = this->lightEmissionAlpha * (1.0f / 255.0f);
        s32 primColorAlpha = (s32)(alphaFraction * 123.0f);
        s32 envColorAlpha = (s32)(alphaFraction * 185.0f);

        AnimatedMat_Draw(play, this->lightEmissionTexScroll);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, primColorAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 215, 215, 255, envColorAlpha);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gStoneTowerTempleMirrorLightEmissionDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
