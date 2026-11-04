// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

s32 SkelAnime_Morph(SkelAnime* skelAnime) {
    f32 prevMorphWeight = skelAnime->morphWeight;
    f32 updateRate = gFramerateDivisorThird;

    skelAnime->morphWeight -= skelAnime->morphRate * updateRate;
    if (skelAnime->morphWeight <= 0.0f) {
        SkelAnime_SetUpdate(skelAnime);
        skelAnime->morphWeight = 0.0f;
    }
    SkelAnime_InterpFrameTable(skelAnime->limbCount, skelAnime->jointTable, skelAnime->jointTable,
                               skelAnime->morphTable, 1.0f - (skelAnime->morphWeight / prevMorphWeight));
    return false;
}
