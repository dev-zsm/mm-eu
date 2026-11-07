// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_bomb2.h"

void EffectSsBomb2_DrawLayered(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTransBillboard;
    MtxF mtx2F;
    Mtx* mtx2;
    Mtx* mtx;
    s32 pad[3];
    f32 scale;
    f32 depth;
    f32 layer2Scale = 0.925f;
    s32 i;

    OPEN_DISPS(gfxCtx);

    depth = this->rDepth;
    scale = this->rScale * 0.01f;
    SkinMatrix_SetTranslate(&mfTrans, this->pos.x, this->pos.y, this->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &play->billboardMtxF, &mfTransBillboard);
    SkinMatrix_MtxFMtxFMult(&mfTransBillboard, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        mtx2 = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

        if (mtx2 != NULL) {
            Gfx_SetupDL60_XluNoCD(gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB,
                            this->rPrimColorA);
            gDPSetEnvColor(POLY_XLU_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, 0);
            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(sLayeredTextures[this->rTexIndex]));
            gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion2DL);
            gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion3DL);

            Matrix_MtxToMtxF(mtx2, &mtx2F);
            Matrix_Put(&mtx2F);

            for (i = 1; i >= 0; i--) {
                Matrix_Translate(0.0f, 0.0f, depth, MTXMODE_APPLY);
                Matrix_RotateZF((this->life * 0.02f) + 180.0f, MTXMODE_APPLY);
                Matrix_Scale(layer2Scale, layer2Scale, layer2Scale, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion3DL);
                layer2Scale -= 0.15f;
            }
        }
    }

    CLOSE_DISPS(gfxCtx);
}
