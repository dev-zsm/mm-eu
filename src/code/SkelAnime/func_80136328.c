// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_InitPlayer(PlayState* play, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg,
                          PlayerAnimationHeader* animation, s32 flags, void* jointTableBuffer, void* morphTableBuffer,
                          s32 limbBufCount) {
    FlexSkeletonHeader* skeletonHeader;
    s32 headerJointCount;
    s32 limbCount;
    size_t allocSize;

    skeletonHeader = Lib_SegmentedToVirtual(skeletonHeaderSeg);
    headerJointCount = skeletonHeader->sh.limbCount;
    skelAnime->initFlags = flags;
    limbCount = (flags & 2) ? headerJointCount : 1;

    if (flags & 1) {
        limbCount += headerJointCount;
    }

    if (flags & 4) {
        limbCount += headerJointCount;
    }

    skelAnime->limbCount = limbCount;
    skelAnime->dListCount = skeletonHeader->dListCount;
    skelAnime->skeleton = Lib_SegmentedToVirtual(skeletonHeader->sh.segment);
    allocSize = sizeof(Vec3s) * limbCount;

    if (flags & 8) {
        allocSize += sizeof(u16);
    }

    if (jointTableBuffer == NULL) {
        skelAnime->jointTable = ZeldaArena_Malloc(allocSize);
        skelAnime->morphTable = ZeldaArena_Malloc(allocSize);
    } else {
        skelAnime->jointTable = (void*)ALIGN16((uintptr_t)jointTableBuffer);
        skelAnime->morphTable = (void*)ALIGN16((uintptr_t)morphTableBuffer);
    }

    PlayerAnimation_Change(play, skelAnime, animation, PLAYER_ANIM_NORMAL_SPEED, 0.0f, 0.0f, ANIMMODE_LOOP, 0.0f);
}
