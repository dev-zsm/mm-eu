// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_DrawKeg(PlayState* play, s32 arg1) {
    s32 temp_s5;
    s32 i;
    PowderKegFuseSegment* fuseSegmentPtr = &sPowderKegFuseSegments[0];
    PowderKegFuseSegment* fuseSegmentPtr2;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Translate(fuseSegmentPtr->pos.x, fuseSegmentPtr->pos.y, fuseSegmentPtr->pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(fuseSegmentPtr->rotX, fuseSegmentPtr->rotY, 0, MTXMODE_APPLY);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gPowderKegFuseMaterialDL);

    temp_s5 = (arg1 / 240) + 1;
    fuseSegmentPtr2 = &sPowderKegFuseSegments[1];

    for (i = 1; i < temp_s5; i++, fuseSegmentPtr2++) {
        Matrix_Translate(fuseSegmentPtr2->pos.x, fuseSegmentPtr2->pos.y, fuseSegmentPtr2->pos.z, MTXMODE_NEW);
        Matrix_RotateZYX(fuseSegmentPtr2->rotX, fuseSegmentPtr2->rotY, 0, MTXMODE_APPLY);
        Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

        if ((i % 2) == 0) {
            gSPDisplayList(POLY_OPA_DISP++, gPowderKegFuseModel1DL);
        } else {
            gSPDisplayList(POLY_OPA_DISP++, gPowderKegFuseModel2DL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
