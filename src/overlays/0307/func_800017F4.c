// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2B274(Actor* thisx, PlayState* play) {
    BgDblueMovebg* this = (BgDblueMovebg*)thisx;
    s16 temp_v1;

    if (this != ref_D_80A2BBF0) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    temp_v1 = ref_D_80A2B96C[ref_func_80A29A80(play, this->switchFlag, this->unk_1BC)];
    if (temp_v1 != 0) {
        if (temp_v1 > 0) {
            Audio_PlaySfx_WaterWheel(&this->dyna.actor.projectedPos, NA_SE_EV_DUMMY_WATER_WHEEL_RR - SFX_FLAG);
        } else {
            Audio_PlaySfx_WaterWheel(&this->dyna.actor.projectedPos, NA_SE_EV_DUMMY_WATER_WHEEL_LR - SFX_FLAG);
        }
    }
}
