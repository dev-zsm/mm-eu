// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81A80(Actor* thisx, PlayState* play) {
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    s32 pad;
    s32 i;
    BgIkanaRotaryroomStruct1* ptr;

    Actor_PlaySfx_Flagged(thisx, NA_SE_EV_EARTHQUAKE - SFX_FLAG);
    this->unk_584--;

    if (this->unk_584 <= 0) {
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        ref_func_80B80894(this, play);

        for (i = 0; i < ARRAY_COUNT(this->unk_2D0); i++) {
            ptr = &this->unk_2D0[i];
            if (ptr->unk_00 != NULL) {
                ((EnTorch2*)ptr->unk_00)->state = 3;
            }
        }

        ref_func_80B81B84(this);
    } else if (this->unk_584 == 15) {
        s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

        Quake_SetSpeed(quakeIndex, 31536);
        Quake_SetPerturbations(quakeIndex, 6, 0, 100, 0);
        Quake_SetDuration(quakeIndex, 22);
    }
}
