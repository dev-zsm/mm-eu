// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_AnimateFrame(SkelAnime* skelAnime) {
    Vec3s nextjointTable[100];

    SkelAnime_GetFrameData(skelAnime->animation, skelAnime->curFrame, skelAnime->limbCount, skelAnime->jointTable);
    if (skelAnime->mode & ANIM_INTERP) {
        s32 frame = skelAnime->curFrame;
        f32 partialFrame = skelAnime->curFrame - frame;

        frame++;
        if (frame >= (s32)skelAnime->animLength) {
            frame = 0;
        }
        SkelAnime_GetFrameData(skelAnime->animation, frame, skelAnime->limbCount, nextjointTable);
        SkelAnime_InterpFrameTable(skelAnime->limbCount, skelAnime->jointTable, skelAnime->jointTable, nextjointTable,
                                   partialFrame);
    }
    if (skelAnime->morphWeight != 0) {
        f32 updateRate = gFramerateDivisorThird;

        skelAnime->morphWeight -= skelAnime->morphRate * updateRate;
        if (skelAnime->morphWeight <= 0.0f) {
            skelAnime->morphWeight = 0.0f;
        } else {
            SkelAnime_InterpFrameTable(skelAnime->limbCount, skelAnime->jointTable, skelAnime->jointTable,
                                       skelAnime->morphTable, skelAnime->morphWeight);
        }
    }
}
