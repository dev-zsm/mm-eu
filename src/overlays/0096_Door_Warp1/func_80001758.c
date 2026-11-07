// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B9BE8(DoorWarp1* this, PlayState* play) {
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WARP_HOLE - SFX_FLAG);
    Math_SmoothStepToF(&this->unk_1B0, 255.0f, 0.2f, 2.0f, 0.1f);
    Math_SmoothStepToF(&this->unk_1B4, 255.0f, 0.2f, 2.0f, 0.1f);
    if (this->unk_1C4 < 10) {
        this->unk_1C4 += 2;
    }

    if (this->unk_1C6 < 120) {
        this->unk_1C6 += 4;
    }

    if (this->unk_1C8 < 230) {
        this->unk_1C8 += 4;
        return;
    }

    this->dyna.actor.parent = NULL;
    if (DoorWarp1_GetRemains(this, play) != DOORWARP1_REMAINS_NONE) {
        this->unk_202 = 1;
        DoorWarp1_SetupAction(this, ref_func_808B9CE8);
    } else {
        DoorWarp1_SetupAction(this, ref_func_808B9F10);
    }
}
