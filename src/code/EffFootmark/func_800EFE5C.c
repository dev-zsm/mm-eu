// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_footmark.h"

void EffFootmark_Update(PlayState* play) {
    EffFootmark* footmark;
    s32 i;

    for (footmark = play->footprintInfo, i = 0; i < ARRAY_COUNT(play->footprintInfo); i++, footmark++) {
        if (footmark->actor == NULL) {
            continue;
        }

        if (CHECK_FLAG_ALL(footmark->flags, FOOTMARK_FLAG_1)) {
            if ((u32)footmark->age < UINT16_MAX) {
                footmark->age++;
            }

            if (footmark->fadeOutDelay == 0) {
                if (footmark->alpha >= footmark->alphaChange + 0x1000) {
                    footmark->alpha -= footmark->alphaChange;
                } else {
                    footmark->actor = NULL;
                }
            } else if (footmark->fadeOutDelay > 0) {
                footmark->fadeOutDelay--;
            }
        }
    }
}
