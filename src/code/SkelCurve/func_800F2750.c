// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fcurve_data_skelanime.h"

void SkelCurve_DrawLimb(PlayState* play, s32 limbIndex, SkelCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw,
                        PostCurveLimbDraw postLimbDraw, s32 lod, Actor* thisx) {
    SkelCurveLimb* limb = Lib_SegmentedToVirtual(skelCurve->skeleton[limbIndex]);

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Push();

    if ((overrideLimbDraw == NULL) ||
        ((overrideLimbDraw != NULL) && overrideLimbDraw(play, skelCurve, limbIndex, thisx))) {
        Vec3f scale;
        Vec3s rot;
        Vec3f pos;
        Gfx* dList;
        s16* jointData = skelCurve->jointTable[limbIndex];

        scale.x = jointData[0] / SKELCURVE_SCALE_SCALE;
        scale.y = jointData[1] / SKELCURVE_SCALE_SCALE;
        scale.z = jointData[2] / SKELCURVE_SCALE_SCALE;
        jointData += 3;
        rot.x = jointData[0];
        rot.y = jointData[1];
        rot.z = jointData[2];
        jointData += 3;
        pos.x = jointData[0];
        pos.y = jointData[1];
        pos.z = jointData[2];

        Matrix_TranslateRotateZYX(&pos, &rot);
        Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);

        if (lod == 0) {
            s32 pad1;

            dList = limb->dList[0];
            if (dList != NULL) {
                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, dList);
            }
        } else if (lod == 1) {
            s32 pad2;

            dList = limb->dList[0];
            if (dList != NULL) {
                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, dList);
            }
            dList = limb->dList[1];
            if (dList != NULL) {
                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, dList);
            }
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, skelCurve, limbIndex, thisx);
    }

    if (limb->child != LIMB_DONE) {
        SkelCurve_DrawLimb(play, limb->child, skelCurve, overrideLimbDraw, postLimbDraw, lod, thisx);
    }

    Matrix_Pop();

    if (limb->sibling != LIMB_DONE) {
        SkelCurve_DrawLimb(play, limb->sibling, skelCurve, overrideLimbDraw, postLimbDraw, lod, thisx);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
