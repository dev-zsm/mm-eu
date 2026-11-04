// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_view.h"

s32 View_StepDistortion(View* view, Mtx* projectionMtx) {
    MtxF projectionMtxF;

    if (view->distortionSpeed == 0.0f) {
        return false;
    }

    if (view->distortionSpeed == 1.0f) {
        view->curDistortionOrientation = view->distortionOrientation;
        view->curDistortionScale = view->distortionScale;
        view->distortionSpeed = 0.0f;
    } else {
        view->curDistortionOrientation.x =
            F32_LERPIMP(view->curDistortionOrientation.x, view->distortionOrientation.x, view->distortionSpeed);
        view->curDistortionOrientation.y =
            F32_LERPIMP(view->curDistortionOrientation.y, view->distortionOrientation.y, view->distortionSpeed);
        view->curDistortionOrientation.z =
            F32_LERPIMP(view->curDistortionOrientation.z, view->distortionOrientation.z, view->distortionSpeed);

        view->curDistortionScale.x =
            F32_LERPIMP(view->curDistortionScale.x, view->distortionScale.x, view->distortionSpeed);
        view->curDistortionScale.y =
            F32_LERPIMP(view->curDistortionScale.y, view->distortionScale.y, view->distortionSpeed);
        view->curDistortionScale.z =
            F32_LERPIMP(view->curDistortionScale.z, view->distortionScale.z, view->distortionSpeed);
    }

    Matrix_MtxToMtxF(projectionMtx, &projectionMtxF);
    Matrix_Put(&projectionMtxF);
    Matrix_RotateXFApply(view->curDistortionOrientation.x);
    Matrix_RotateYF(view->curDistortionOrientation.y, MTXMODE_APPLY);
    Matrix_RotateZF(view->curDistortionOrientation.z, MTXMODE_APPLY);
    Matrix_Scale(view->curDistortionScale.x, view->curDistortionScale.y, view->curDistortionScale.z, MTXMODE_APPLY);
    Matrix_RotateZF(-view->curDistortionOrientation.z, MTXMODE_APPLY);
    Matrix_RotateYF(-view->curDistortionOrientation.y, MTXMODE_APPLY);
    Matrix_RotateXFApply(-view->curDistortionOrientation.x);
    Matrix_ToMtx(projectionMtx);

    return true;
}
