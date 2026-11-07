// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void DmChar05_Draw(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;

    switch (DMCHAR05_GET(&this->actor)) {
        case DMCHAR05_0:
            ref_func_80AAD998(thisx, play);
            break;

        case DMCHAR05_1:
            ref_func_80AADA90(thisx, play);
            break;

        case DMCHAR05_2:
            ref_func_80AADB4C(thisx, play);
            break;

        case DMCHAR05_3:
            ref_func_80AADC00(thisx, play);
            break;

        case DMCHAR05_4:
            ref_func_80AAE030(play, this);
            break;

        case DMCHAR05_5:
        case DMCHAR05_6:
        case DMCHAR05_7:
        case DMCHAR05_8:
        case DMCHAR05_9:
        case DMCHAR05_10:
        case DMCHAR05_11:
        case DMCHAR05_12:
            ref_func_80AAE114(play, this);
            break;
    }
}
