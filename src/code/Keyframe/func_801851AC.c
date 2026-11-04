// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

void Keyframe_DrawFlexLimb(PlayState* play, KFSkelAnimeFlex* kfSkelAnime, s32* limbIndex,
                           OverrideKeyframeDrawScaled overrideKeyframeDraw, PostKeyframeDrawScaled postKeyframeDraw,
                           void* arg, Mtx** mtxStack) {
    KeyFrameFlexLimb* limb = Lib_SegmentedToVirtual(kfSkelAnime->skeleton->limbs);
    s32 i;
    Gfx* newDList;
    Gfx* limbDList;
    u8 drawFlags;
    Vec3f scale;
    Vec3s rot;
    Vec3f pos;
    Vec3s* jointData;

    OPEN_DISPS(play->state.gfxCtx);

    limb += *limbIndex;
    jointData = &kfSkelAnime->jointTable[*limbIndex * 3];

    scale.x = jointData->x * 0.01f;
    scale.y = jointData->y * 0.01f;
    scale.z = jointData->z * 0.01f;

    jointData++;

    rot.x = jointData->x;
    rot.y = jointData->y;
    rot.z = jointData->z;

    jointData++;

    pos.x = jointData->x;
    pos.y = jointData->y;
    pos.z = jointData->z;

    Matrix_Push();

    newDList = limbDList = limb->dList;
    drawFlags = limb->drawFlags;

    if (overrideKeyframeDraw == NULL ||
        (overrideKeyframeDraw != NULL &&
         overrideKeyframeDraw(play, kfSkelAnime, *limbIndex, &newDList, &drawFlags, arg, &scale, &rot, &pos))) {
        if ((kfSkelAnime->transformCallbacks == NULL) || (limb->callbackIndex == KF_CALLBACK_INDEX_NONE) ||
            (kfSkelAnime->transformCallbacks[limb->callbackIndex] == NULL) ||
            kfSkelAnime->transformCallbacks[limb->callbackIndex](play, kfSkelAnime, *limbIndex, &newDList, &drawFlags,
                                                                 arg)) {

            Matrix_TranslateRotateZYX(&pos, &rot);

            if (scale.x != 1.0f || scale.y != 1.0f || scale.z != 1.0f) {
                Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);
            }

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
                gSPMatrix(POLY_OPA_DISP++, *mtxStack, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                Matrix_ToMtx(*mtxStack);

                (*mtxStack)++;
            }
        }
    }

    if (postKeyframeDraw != NULL) {
        postKeyframeDraw(play, kfSkelAnime, *limbIndex, &newDList, &drawFlags, arg, &scale, &rot, &pos);
    }

    (*limbIndex)++;

    for (i = 0; i < limb->numChildren; i++) {
        Keyframe_DrawFlexLimb(play, kfSkelAnime, limbIndex, overrideKeyframeDraw, postKeyframeDraw, arg, mtxStack);
    }

    Matrix_Pop();
    CLOSE_DISPS(play->state.gfxCtx);
}
