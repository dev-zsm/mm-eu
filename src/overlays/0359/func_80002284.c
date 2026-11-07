// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_FireRing_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnFall* this = (EnFall*)thisx;

    if (!(this->fireRingAlpha <= 0.0f)) {
        if (this->fireRingAlpha > 1.0f) {
            this->fireRingAlpha = 1.0f;
        }

        OPEN_DISPS(play->state.gfxCtx);

        AnimatedMat_DrawXlu(play, Lib_SegmentedToVirtual(gMoonFireRingTexAnim));
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
        gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, (s32)(this->fireRingAlpha * 255.0f));

        gSPDisplayList(POLY_XLU_DISP++, gMoonFireRingDL);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
