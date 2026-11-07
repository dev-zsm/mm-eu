// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_stk.h"

void EffStk_Draw(Actor* thisx, PlayState* play) {
    EffStk* this = (EffStk*)thisx;
    s32 pad;
    Camera* activeCam = GET_ACTIVE_CAM(play);
    Vec3f eye = activeCam->eye;
    Vec3f quakeOffset;

    quakeOffset = Camera_GetQuakeOffset(activeCam);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_Translate(eye.x + quakeOffset.x, eye.y + quakeOffset.y, eye.z + quakeOffset.z, MTXMODE_NEW);
    Matrix_Scale(0.2f, 0.2f, 0.2f, MTXMODE_APPLY);
    Matrix_ReplaceRotation(&play->billboardMtxF);
    Matrix_Translate(0.0f, 0.0f, this->unk148, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    AnimatedMat_DrawAlphaStep(play, Lib_SegmentedToVirtual(object_stk2_Matanimheader_009F60), 1.0f, this->unk144);
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
    gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
    gSPDisplayList(POLY_XLU_DISP++, object_stk2_DL_008920);
    gSPDisplayList(POLY_XLU_DISP++, object_stk2_DL_008A38);

    CLOSE_DISPS(play->state.gfxCtx);
}
