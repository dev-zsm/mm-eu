// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

s32 PlayerAnimation_Once(PlayState* play, SkelAnime* skelAnime) {
    f32 updateRate = (s32)play->state.framerateDivisor * 0.5f;

    if (skelAnime->curFrame == skelAnime->endFrame) {
        PlayerAnimation_AnimateFrame(play, skelAnime);
        return true;
    }

    skelAnime->curFrame += skelAnime->playSpeed * updateRate;

    if (((skelAnime->curFrame - skelAnime->endFrame) * skelAnime->playSpeed) > 0.0f) {
        skelAnime->curFrame = skelAnime->endFrame;
    } else {
        if (skelAnime->curFrame < 0.0f) {
            skelAnime->curFrame += skelAnime->animLength;
        } else if (skelAnime->animLength <= skelAnime->curFrame) {
            skelAnime->curFrame -= skelAnime->animLength;
        }
    }
    PlayerAnimation_AnimateFrame(play, skelAnime);
    return false;
}
