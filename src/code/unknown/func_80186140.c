// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

void Keyframe_DrawStandardLimb(PlayState* play, KFSkelAnime* kfSkelAnime, s32* limbIndex,
                               OverrideKeyframeDraw overrideKeyframeDraw, PostKeyframeDraw postKeyframeDraw, void* arg,
                               Mtx** mtxStack) {
    KeyFrameStandardLimb* limb =
        *limbIndex + (KeyFrameStandardLimb*)Lib_SegmentedToVirtual(kfSkelAnime->skeleton->limbs);
    s32 i;
    Gfx* newDList;
    Gfx* limbDList;
    u8 drawFlags;
    Vec3s rot;
    Vec3s* jointData = &kfSkelAnime->jointTable[*limbIndex];
    Vec3f pos;

    if (*limbIndex != 0) {
        pos.x = limb->jointPos.x;
        pos.y = limb->jointPos.y;
        pos.z = limb->jointPos.z;
    } else {
        pos.x = jointData->x;
        pos.y = jointData->y;
        pos.z = jointData->z;
    }

    jointData++;

    rot.x = jointData->x;
    rot.y = jointData->y;
    rot.z = jointData->z;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Push();

    newDList = limbDList = limb->dList;
    drawFlags = limb->drawFlags;

    if (overrideKeyframeDraw == NULL ||
        (overrideKeyframeDraw != NULL &&
         overrideKeyframeDraw(play, kfSkelAnime, *limbIndex, &newDList, &drawFlags, arg, &rot, &pos))) {

        Matrix_TranslateRotateZYX(&pos, &rot);

        if (newDList != NULL) {
            Matrix_ToMtx(*mtxStack);

            if (drawFlags & KEYFRAME_DRAW_XLU) {
                gSPMatrix(POLY_XLU_DISP++, *mtxStack, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, newDList);
            } else {
                gSPMatrix(POLY_OPA_DISP++, *mtxStack, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, newDList);
            }
            (*mtxStack)++;
        } else if (limbDList != NULL) {
            Matrix_ToMtx(*mtxStack);

            gSPMatrix(POLY_OPA_DISP++, *mtxStack, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            (*mtxStack)++;
        }
    }

    if (postKeyframeDraw != NULL) {
        postKeyframeDraw(play, kfSkelAnime, *limbIndex, &newDList, &drawFlags, arg, &rot, &pos);
    }

    (*limbIndex)++;

    for (i = 0; i < limb->numChildren; i++) {
        Keyframe_DrawStandardLimb(play, kfSkelAnime, limbIndex, overrideKeyframeDraw, postKeyframeDraw, arg, mtxStack);
    }

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);
}
