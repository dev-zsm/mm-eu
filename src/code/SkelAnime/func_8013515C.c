// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

Gfx* SkelAnime_DrawFlex(PlayState* play, void** skeleton, Vec3s* jointTable, s32 dListCount,
                        OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, Actor* actor, Gfx* gfx) {
    StandardLimb* rootLimb;
    s32 pad;
    Gfx* newDList;
    Gfx* limbDList;
    Vec3f pos;
    Vec3s rot;
    Mtx* mtx;

    if (skeleton == NULL) {
        return NULL;
    }

    mtx = GRAPH_ALLOC(play->state.gfxCtx, dListCount * sizeof(Mtx));

    gSPSegment(gfx++, 0x0D, mtx);

    Matrix_Push();

    rootLimb = Lib_SegmentedToVirtual(skeleton[0]);

    pos.x = jointTable[LIMB_ROOT_POS].x;
    pos.y = jointTable[LIMB_ROOT_POS].y;
    pos.z = jointTable[LIMB_ROOT_POS].z;

    rot = jointTable[LIMB_ROOT_ROT];

    newDList = limbDList = rootLimb->dList;

    if ((overrideLimbDraw == NULL) || !overrideLimbDraw(play, 1, &newDList, &pos, &rot, actor, &gfx)) {
        Matrix_TranslateRotateZYX(&pos, &rot);
        if (newDList != NULL) {
            gSPMatrix(&gfx[0], Matrix_ToMtx(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(&gfx[1], newDList);
            gfx = &gfx[2];
            mtx++;
        } else {
            if (limbDList != NULL) {
                Matrix_ToMtx(mtx);
                mtx++;
            }
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, 1, &limbDList, &rot, actor, &gfx);
    }

    if (rootLimb->child != LIMB_DONE) {
        gfx = SkelAnime_DrawFlexLimb(play, rootLimb->child, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor,
                                     &mtx, gfx);
    }

    Matrix_Pop();

    return gfx;
}
