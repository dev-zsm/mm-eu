// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81DC8(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;

    if (this->unk_584 > 10) {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_EARTHQUAKE - SFX_FLAG);
    }
    this->unk_584--;

    if (this->unk_584 <= 0) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        ref_func_80B818B4(this);
    } else if (this->unk_584 == 19) {
        s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

        Quake_SetSpeed(quakeIndex, 20000);
        Quake_SetPerturbations(quakeIndex, 5, 0, 40, 60);
        Quake_SetDuration(quakeIndex, 17);
    }
}
