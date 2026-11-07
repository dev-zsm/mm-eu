// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_ripple.h"

void EffectSsGRipple_DrawRipple(PlayState* play2, EffectSs* this, TexturePtr tex) {
    PlayState* play = play2;
    f32 radius;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    Mtx* mtx;
    f32 yPos;
    CollisionHeader* colHeader;

    OPEN_DISPS(gfxCtx);

    radius = this->rRadius * 0.0025f;
    colHeader = BgCheck_GetCollisionHeader(&play->colCtx, this->rBgId);

    if ((this->rWaterBoxNum != -1) && (colHeader != NULL) && (this->rWaterBoxNum < colHeader->numWaterBoxes)) {
        yPos = WaterBox_GetSurface(&play->colCtx, this->rWaterBoxNum, this->rBgId);
    } else {
        yPos = this->pos.y;
    }

    SkinMatrix_SetTranslate(&mfTrans, this->pos.x, yPos, this->pos.z);
    SkinMatrix_SetScale(&mfScale, radius, radius, radius);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        Gfx_SetupDL60_XluNoCD(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB,
                        this->rPrimColorA);
        gDPSetEnvColor(POLY_XLU_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, this->rEnvColorA);
        gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
        gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
        gSPDisplayList(POLY_XLU_DISP++, this->gfx);
    }

    CLOSE_DISPS(gfxCtx);
}
