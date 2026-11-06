// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

s32 ref_func_80B83D04(BgDblueWaterfall* this, PlayState* play) {
    s32 phi_v1;
    s32 sp18 = BGDBLUEWATERFALL_GET_100(&this->actor);

    if (Flags_GetSwitch(play, BGDBLUEWATERFALL_GET_SWITCH_FLAG(&this->actor))) {
        phi_v1 = true;
    } else {
        phi_v1 = false;
    }
    return phi_v1 ^ sp18;
}
