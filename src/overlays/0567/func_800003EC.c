// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void EffKamejimaWave_Draw(Actor* thisx, PlayState* play) {
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;

    Environment_LerpSandstormColors(sPrimColors, &primColor);
    Environment_LerpSandstormColors(sEnvColors, &envColor);
    EffKamejimaWave_SetVtxAlpha(sVtxAlpha);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_Scale(6.0f, 5.0f, 5.0f, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    AnimatedMat_Draw(play, ref_D_80BCF1C4);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, primColor.r, primColor.g, primColor.b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, envColor.r, envColor.g, envColor.b, 255);
    gSPDisplayList(POLY_XLU_DISP++, gTurtleWaveDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
