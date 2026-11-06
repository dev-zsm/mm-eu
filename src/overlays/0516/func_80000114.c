// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B83D94(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;
    s32 switchFlag = BGDBLUEWATERFALL_GET_SWITCH_FLAG(&this->actor);
    s32 sp1C = BGDBLUEWATERFALL_GET_100(&this->actor);
    s32 phi_v0;

    if (Flags_GetSwitch(play, switchFlag)) {
        phi_v0 = true;
    } else {
        phi_v0 = false;
    }

    if (phi_v0 != sp1C) {
        if (phi_v0) {
            Flags_UnsetSwitch(play, switchFlag);
        } else {
            Flags_SetSwitch(play, switchFlag);
        }
    }
}
