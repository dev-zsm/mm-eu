// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void BgDblueWaterfall_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    BgDblueWaterfall* this = (BgDblueWaterfall*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    if (this->unk_19E > 0) {
        s32 sp38 = this->unk_19E * 0.49803922f;

        AnimatedMat_Draw(play, this->unk_190);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x8A, 255, 255, 255, sp38);
        gSPDisplayList(POLY_XLU_DISP++, gGreatBayTempleObjectWaterfallDL);
    }

    if (this->unk_19F > 0) {
        if (this->unk_19F < 255) {
            gSPSegment(POLY_XLU_DISP++, 0x09, gActorSetupXluDL);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x9B, 255, 255, 255, this->unk_19F);
            gSPDisplayList(POLY_XLU_DISP++, gGreatBayTempleObjectIceStalactiteDL);
        } else {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);

            gSPSegment(POLY_OPA_DISP++, 0x09, gActorSetupOpaDL);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x9B, 255, 255, 255, 255);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, gGreatBayTempleObjectIceStalactiteDL);
        }

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0xFF, 255, 255, 255, this->unk_19F);
        gSPDisplayList(POLY_XLU_DISP++, gGreatBayTempleObjectIceStalactiteRimDL);
    }

    if (this->unk_1A0 > 0) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0xFF, 255, 255, 255, this->unk_1A0);
        gSPDisplayList(POLY_XLU_DISP++, gGreatBayTempleObjectFrozenWaterfallDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
