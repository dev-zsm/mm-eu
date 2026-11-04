// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

Gfx* SkelAnime_DrawFlexLimb(PlayState* play, s32 limbIndex, void** skeleton, Vec3s* jointTable,
                            OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, Actor* actor, Mtx** mtx,
                            Gfx* gfx) {
    StandardLimb* limb;
    Gfx* newDList;
    Gfx* limbDList;
    Vec3f pos;
    Vec3s rot;

    Matrix_Push();

    limb = Lib_SegmentedToVirtual(skeleton[limbIndex]);
    limbIndex++;
    rot = jointTable[limbIndex];

    pos.x = limb->jointPos.x;
    pos.y = limb->jointPos.y;
    pos.z = limb->jointPos.z;

    newDList = limbDList = limb->dList;

    if ((overrideLimbDraw == NULL) || !overrideLimbDraw(play, limbIndex, &newDList, &pos, &rot, actor, &gfx)) {
        Matrix_TranslateRotateZYX(&pos, &rot);
        if (newDList != NULL) {
            gSPMatrix(&gfx[0], Matrix_ToMtx(*mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(&gfx[1], newDList);
            gfx = &gfx[2];
            (*mtx)++;
        } else {
            if (limbDList != NULL) {
                Matrix_ToMtx(*mtx);
                (*mtx)++;
            }
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, limbIndex, &limbDList, &rot, actor, &gfx);
    }

    if (limb->child != LIMB_DONE) {
        gfx = SkelAnime_DrawFlexLimb(play, limb->child, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor,
                                     mtx, gfx);
    }

    Matrix_Pop();

    if (limb->sibling != LIMB_DONE) {
        gfx = SkelAnime_DrawFlexLimb(play, limb->sibling, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor,
                                     mtx, gfx);
    }

    return gfx;
}
