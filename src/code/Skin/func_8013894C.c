// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_awb.h"

void Skin_Init(GameState* gameState, Skin* skin, SkeletonHeader* skeletonHeader, AnimationHeader* animationHeader) {
    s32 limbCount;
    s32 i;
    SkinLimb** skeleton;
    SkeletonHeader* virtSkelHeader = Lib_SegmentedToVirtual(skeletonHeader);

    skin->limbCount = virtSkelHeader->limbCount;
    skin->skeletonHeader = virtSkelHeader;
    limbCount = skin->skeletonHeader->limbCount;

    skeleton = Lib_SegmentedToVirtual(skin->skeletonHeader->segment);
    skin->vtxTable = ZeldaArena_Malloc(limbCount * sizeof(SkinLimbVtx));

    for (i = 0; i < limbCount; i++) {
        SkinLimbVtx* vtxEntry = &skin->vtxTable[i];

        if ((((SkinLimb*)Lib_SegmentedToVirtual(skeleton[i]))->segmentType != SKIN_LIMB_TYPE_ANIMATED) ||
            (((SkinLimb*)Lib_SegmentedToVirtual(skeleton[i]))->segment == NULL)) {
            vtxEntry->index = 0;

            vtxEntry->buf[0] = NULL;
            vtxEntry->buf[1] = NULL;
        } else {
            SkinAnimatedLimbData* animatedLimbData =
                Lib_SegmentedToVirtual((((SkinLimb*)Lib_SegmentedToVirtual(skeleton[i]))->segment));

            { s32 tmp; }

            vtxEntry->index = 0;
            vtxEntry->buf[0] = ZeldaArena_Malloc(animatedLimbData->totalVtxCount * sizeof(Vtx));
            vtxEntry->buf[1] = ZeldaArena_Malloc(animatedLimbData->totalVtxCount * sizeof(Vtx));

            Skin_InitAnimatedLimb(gameState, skin, i);
        }
    }

    SkelAnime_InitSkin(gameState, &skin->skelAnime, skeletonHeader, animationHeader);
}
