// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B90CC(DoorWarp1* this, PlayState* play) {
    s32 pad[2];
    s16 sp2E = 0;
    f32 phi_f0 = 0.0f;

    if (play->sceneId == SCENE_MITURIN) {
        sp2E = -10;
        phi_f0 = -5.0f;
    } else if (play->sceneId == SCENE_HAKUGIN) {
        sp2E = -20;
    } else if (play->sceneId == SCENE_SEA) {
        sp2E = -20;
    }

    Math_SmoothStepToF(&this->unk_1AC, 40.0f, 0.5f, 1.2f + phi_f0, 0.01f);
    Math_SmoothStepToF(&this->unk_1A4, 0.0f, 0.5f, 12.0f, 0.1f);
    if ((this->unk_1A4 < 460.0f) && (this->unk_1A4 > 100.0f)) {
        ref_func_808BB8D4(this, play, 6);
    }

    if (this->unk_1A4 < 0.1f) {
        this->unk_1D0 = sp2E + 30;
        this->unk_1D4 = 0;
        DoorWarp1_SetupAction(this, ref_func_808B921C);
    }

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WARP_HOLE_ENERGY - SFX_FLAG);
}
