// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_800001A8(Actor* thisx, PlayState* play) {
    DemoEffect* this = (DemoEffect*)thisx;

    switch (DEMO_EFFECT_GET_TYPE(&this->actor)) {
        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_LARGE:
        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_SMALL:
        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_LARGE:
        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_VERY_LARGE:
            SkelCurve_Destroy(play, &this->skelCurve);
            break;

        default:
            break;
    }
}
