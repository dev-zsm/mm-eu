// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin.h"

void Skin_DrawLimb(GraphicsContext* gfxCtx, Skin* skin, s32 limbIndex, Gfx* dList, s32 drawFlags) {
    Gfx* limbDList = dList;
    SkinLimb** skeleton;

    OPEN_DISPS(gfxCtx);

    skeleton = Lib_SegmentedToVirtual(skin->skeletonHeader->segment);

    if (dList == NULL) {
        limbDList = ((SkinLimb*)Lib_SegmentedToVirtual(skeleton[limbIndex]))->segment;
    }

    if (limbDList != NULL) {
        Mtx* mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &gSkinLimbMatrices[limbIndex]);

        if (mtx != NULL) {
            gSPMatrix(POLY_OPA_DISP++, mtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, limbDList);
            gSPPopMatrix(POLY_OPA_DISP++, G_MTX_MODELVIEW);
            gDPPipeSync(POLY_OPA_DISP++);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
