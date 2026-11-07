// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B818C8(Actor* thisx, PlayState* play) {
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    s32 switchFlag;

    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        switchFlag = BGIKANAROTARYROOM_GET_SWITCH_FLAG_1(&this->dyna.actor);
        if (Flags_GetSwitch(play, switchFlag)) {
            Flags_UnsetSwitch(play, switchFlag);
        } else {
            Flags_SetSwitch(play, switchFlag);
        }
        ref_func_80B81978(this);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
