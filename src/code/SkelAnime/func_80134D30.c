// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

Gfx* SkelAnime_Draw(PlayState* play, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw,
                    PostLimbDraw postLimbDraw, Actor* actor, Gfx* gfx) {
    StandardLimb* rootLimb;
    s32 pad;
    Gfx* dList;
    Vec3f pos;
    Vec3s rot;

    if (skeleton == NULL) {
        return NULL;
    }

    Matrix_Push();

    rootLimb = Lib_SegmentedToVirtual(skeleton[0]);

    pos.x = jointTable[LIMB_ROOT_POS].x;
    pos.y = jointTable[LIMB_ROOT_POS].y;
    pos.z = jointTable[LIMB_ROOT_POS].z;

    rot = jointTable[LIMB_ROOT_ROT];

    dList = rootLimb->dList;

    if ((overrideLimbDraw == NULL) || !overrideLimbDraw(play, 1, &dList, &pos, &rot, actor, &gfx)) {
        Matrix_TranslateRotateZYX(&pos, &rot);
        if (dList != NULL) {
            MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);
            gSPDisplayList(&gfx[1], dList);
            gfx = &gfx[2];
        }
    }

    if (postLimbDraw != NULL) {
        postLimbDraw(play, 1, &dList, &rot, actor, &gfx);
    }

    if (rootLimb->child != LIMB_DONE) {
        gfx =
            SkelAnime_DrawLimb(play, rootLimb->child, skeleton, jointTable, overrideLimbDraw, postLimbDraw, actor, gfx);
    }

    Matrix_Pop();

    return gfx;
}
