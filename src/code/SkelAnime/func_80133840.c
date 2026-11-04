// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_DrawFlexLimbLod(PlayState* play, s32 limbIndex, void** skeleton, Vec3s* jointTable,
                               OverrideLimbDrawFlex overrideLimbDraw, PostLimbDrawFlex postLimbDraw, Actor* actor,
                               s32 lod, Mtx** mtx) {
    LodLimb* limb;
    Gfx* newDList;
    Gfx* limbDList;
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

    newDList = limbDList = limb->dLists[lod];

    if ((overrideLimbDraw == NULL) || !overrideLimbDraw(play, limbIndex, &newDList, &pos, &rot, actor)) {
        Matrix_TranslateRotateZYX(&pos, &rot);
        if (newDList != NULL) {
            Matrix_ToMtx(*mtx);
            gSPMatrix(POLY_OPA_DISP++, *mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, newDList);
            (*mtx)++;
        } else if (limbDList != NULL) {
            Matrix_ToMtx(*mtx);
            (*mtx)++;
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, limbIndex, &newDList, &limbDList, &rot, actor);
    }

    if (limb->child != LIMB_DONE) {
        SkelAnime_DrawFlexLimbLod(play, limb->child, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor, lod,
                                  mtx);
    }

    Matrix_Pop();

    if (limb->sibling != LIMB_DONE) {
        SkelAnime_DrawFlexLimbLod(play, limb->sibling, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor, lod,
                                  mtx);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
