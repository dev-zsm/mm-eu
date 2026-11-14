// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt2_ChangeAnim), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_trt2.h"

void func_80000000(SkelAnime* skelAnime, AnimationInfoS* animationInfo, s32 animIndex) {
    f32 endFrame;

    animationInfo += animIndex;

    if (animationInfo->frameCount < 0) {
        endFrame = Animation_GetLastFrame(animationInfo->animation);
    } else {
        endFrame = animationInfo->frameCount;
    }
    Animation_Change(skelAnime, animationInfo->animation, animationInfo->playSpeed, animationInfo->startFrame, endFrame,
                     animationInfo->mode, animationInfo->morphFrames);
}
