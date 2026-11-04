// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

s32 SkelAnime_MorphTaper(SkelAnime* skelAnime) {
    s16 prevPhase = skelAnime->morphWeight * 0x4000;
    s16 curPhase;
    f32 prevWeight;
    f32 curWeight;
    f32 updateRate = gFramerateDivisorThird;

    skelAnime->morphWeight -= skelAnime->morphRate * updateRate;
    if (skelAnime->morphWeight <= 0.0f) {
        SkelAnime_SetUpdate(skelAnime);
        skelAnime->morphWeight = 0.0f;
    }
    curPhase = skelAnime->morphWeight * 0x4000;
    if (skelAnime->taper < 0) {
        prevWeight = 1.0f - Math_CosS(prevPhase);
        curWeight = 1.0f - Math_CosS(curPhase);
    } else {
        prevWeight = Math_SinS(prevPhase);
        curWeight = Math_SinS(curPhase);
    }
    if (curWeight != 0.0f) {
        curWeight /= prevWeight;
    } else {
        curWeight = 0.0f;
    }
    SkelAnime_InterpFrameTable(skelAnime->limbCount, skelAnime->jointTable, skelAnime->jointTable,
                               skelAnime->morphTable, 1.0f - curWeight);
    return false;
}
