// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_DrawLimbLod(PlayState* play, s32 limbIndex, void** skeleton, Vec3s* jointTable,
                           OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, Actor* actor, s32 lod) {
    LodLimb* limb;
    Gfx* dList;
    Vec3f pos;
    Vec3s rot;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Push();
    limb = Lib_SegmentedToVirtual(skeleton[limbIndex]);
    limbIndex++;
    rot = jointTable[limbIndex];

    pos.x = limb->jointPos.x;
    pos.y = limb->jointPos.y;
    pos.z = limb->jointPos.z;

    dList = limb->dLists[lod];
    if ((overrideLimbDraw == NULL) || !overrideLimbDraw(play, limbIndex, &dList, &pos, &rot, actor)) {
        Matrix_TranslateRotateZYX(&pos, &rot);
        if (dList != NULL) {
            Gfx* gfx = POLY_OPA_DISP;

            MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);

            gSPDisplayList(&gfx[1], dList);
            POLY_OPA_DISP = &gfx[2];
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, limbIndex, &dList, &rot, actor);
    }

    if (limb->child != LIMB_DONE) {
        SkelAnime_DrawLimbLod(play, limb->child, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor, lod);
    }

    Matrix_Pop();

    if (limb->sibling != LIMB_DONE) {
        SkelAnime_DrawLimbLod(play, limb->sibling, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor, lod);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
