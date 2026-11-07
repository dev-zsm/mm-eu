// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4F4C8(Actor* thisx, PlayState* play) {
    s32 pad;
    Gfx* gfx;
    MtxF* matrix;
    EnMkkModelInfo* modelInfo = &sBoeModelInfo[thisx->params];
    EnMkk* this = (EnMkk*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_XLU_DISP;
    gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);
    gDPSetEnvColor(&gfx[1], 255, 255, 255, this->alpha);
    gSPDisplayList(&gfx[2], modelInfo->materialDL);
    Matrix_ReplaceRotation(&play->billboardMtxF);
    MATRIX_FINALIZE_AND_LOAD(&gfx[3], play->state.gfxCtx);
    gSPDisplayList(&gfx[4], modelInfo->modelDL);

    matrix = Matrix_GetCurrent();
    matrix->mf[3][0] = this->unk_154.x;
    matrix->mf[3][1] = this->unk_154.y + 5.0f;
    matrix->mf[3][2] = this->unk_154.z;

    MATRIX_FINALIZE_AND_LOAD(&gfx[5], play->state.gfxCtx);
    gSPDisplayList(&gfx[6], modelInfo->modelDL);

    matrix->mf[3][0] = this->unk_160.x;
    matrix->mf[3][1] = this->unk_160.y + 5.0f;
    matrix->mf[3][2] = this->unk_160.z;

    MATRIX_FINALIZE_AND_LOAD(&gfx[7], play->state.gfxCtx);
    gSPDisplayList(&gfx[8], modelInfo->modelDL);

    matrix->mf[3][0] = this->unk_16C.x;
    matrix->mf[3][1] = this->unk_16C.y + 5.0f;
    matrix->mf[3][2] = this->unk_16C.z;

    MATRIX_FINALIZE_AND_LOAD(&gfx[9], play->state.gfxCtx);
    gSPDisplayList(&gfx[10], modelInfo->modelDL);
    gSPDisplayList(&gfx[11], modelInfo->endDL);
    POLY_XLU_DISP = &gfx[12];

    CLOSE_DISPS(play->state.gfxCtx);
}
