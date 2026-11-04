// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void EnMkk_Draw(Actor* thisx, PlayState* play) {
    EnMkkModelInfo* modelInfo = &sBoeModelInfo[thisx->params];
    Gfx* gfx;
    Color_RGBA8* primColors;
    EnMkk* this = (EnMkk*)thisx;

    if (this->actor.projectedPos.z > 0.0f) {
        MtxF* matrix;

        OPEN_DISPS(play->state.gfxCtx);

        if (this->alpha == 255) {
            primColors = &ref_D_80A4F7C4[this->primColorSelect];
            gfx = POLY_OPA_DISP;
            gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);
            gDPSetPrimColor(&gfx[1], 0, 0xFF, primColors->r, primColors->g, primColors->b, primColors->a);
            gSPSegment(&gfx[2], 0x08, gActorSetupOpaDL);

            MATRIX_FINALIZE_AND_LOAD(&gfx[3], play->state.gfxCtx);
            gSPDisplayList(&gfx[4], modelInfo->eyesDL);
            POLY_OPA_DISP = &gfx[5];
        }
        gfx = POLY_XLU_DISP;
        gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);
        gDPSetEnvColor(&gfx[1], 255, 255, 255, this->alpha);
        gSPDisplayList(&gfx[2], modelInfo->materialDL);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        MATRIX_FINALIZE_AND_LOAD(&gfx[3], play->state.gfxCtx);
        gSPDisplayList(&gfx[4], modelInfo->modelDL);
        if (thisx->params == 0) {
            matrix = Matrix_GetCurrent();
            matrix->mf[3][0] = this->unk_154.x;
            matrix->mf[3][1] = this->unk_154.y + 8.5f;
            matrix->mf[3][2] = this->unk_154.z;

            Matrix_Scale(0.85f, 0.85f, 0.85f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(&gfx[5], play->state.gfxCtx);
            gSPDisplayList(&gfx[6], modelInfo->modelDL);

            matrix->mf[3][0] = this->unk_160.x;
            matrix->mf[3][1] = this->unk_160.y + 7225.0f * 0.001f;
            matrix->mf[3][2] = this->unk_160.z;

            Matrix_Scale(0.85f, 0.85f, 0.85f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(&gfx[7], play->state.gfxCtx);
            gSPDisplayList(&gfx[8], modelInfo->modelDL);
            gSPDisplayList(&gfx[9], modelInfo->endDL);

            POLY_XLU_DISP = &gfx[10];
        } else {
            gSPDisplayList(&gfx[5], modelInfo->endDL);
            POLY_XLU_DISP = &gfx[6];
        }
    }
    CLOSE_DISPS(play->state.gfxCtx);
}
