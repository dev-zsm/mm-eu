// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

s32 SkelAnime_LoopPartial(SkelAnime* skelAnime) {
    f32 updateRate = gFramerateDivisorThird;

    skelAnime->curFrame += skelAnime->playSpeed * updateRate;
    if (skelAnime->curFrame < skelAnime->startFrame) {
        skelAnime->curFrame = (skelAnime->curFrame - skelAnime->startFrame) + skelAnime->endFrame;
    } else if (skelAnime->endFrame <= skelAnime->curFrame) {
        skelAnime->curFrame = (skelAnime->curFrame - skelAnime->endFrame) + skelAnime->startFrame;
    }

    SkelAnime_AnimateFrame(skelAnime);
    return false;
}
