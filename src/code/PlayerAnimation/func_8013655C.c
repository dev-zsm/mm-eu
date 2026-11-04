// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void PlayerAnimation_AnimateFrame(PlayState* play, SkelAnime* skelAnime) {
    AnimTaskQueue_AddLoadPlayerFrame(play, skelAnime->animation, skelAnime->curFrame, skelAnime->limbCount,
                                     skelAnime->jointTable);
    if (skelAnime->morphWeight != 0) {
        f32 updateRate = (s32)play->state.framerateDivisor * 0.5f;
        skelAnime->morphWeight -= skelAnime->morphRate * updateRate;
        if (skelAnime->morphWeight <= 0.0f) {
            skelAnime->morphWeight = 0.0f;
        } else {
            AnimTaskQueue_AddInterp(play, skelAnime->limbCount, skelAnime->jointTable, skelAnime->morphTable,
                                    skelAnime->morphWeight);
        }
    }
}
