// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kirakira.h"

void EffectSsKirakira_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx;
    f32 scale = this->rScale / 10000.0f;
    s32 pad;
    MtxF mfTrans;
    MtxF mfRot;
    MtxF mfScale;
    MtxF mfTransBillboard;
    MtxF mfTransBillboardRot;
    MtxF mfResult;
    Mtx* mtx;

    gfxCtx = play->state.gfxCtx;

    OPEN_DISPS(gfxCtx);

    SkinMatrix_SetTranslate(&mfTrans, this->pos.x, this->pos.y, this->pos.z);
    SkinMatrix_SetRotateRPY(&mfRot, 0, 0, this->rYaw);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &play->billboardMtxF, &mfTransBillboard);
    SkinMatrix_MtxFMtxFMult(&mfTransBillboard, &mfRot, &mfTransBillboardRot);
    SkinMatrix_MtxFMtxFMult(&mfTransBillboardRot, &mfScale, &mfResult);
    gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        Gfx_SetupDL25_Xlu(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB,
                        (((s8)((55.0f / this->rLifespan) * this->life) + 200)));
        gDPSetEnvColor(POLY_XLU_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, this->rEnvColorA);
        gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
        gSPDisplayList(POLY_XLU_DISP++, this->gfx);
        gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
    }

    CLOSE_DISPS(gfxCtx);
}
