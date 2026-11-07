// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B98A8(DoorWarp1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (this->unk_1CA > 100) {
        if (player->actor.velocity.y < 10.0f) {
            player->actor.gravity = 0.1f;
        } else {
            player->actor.gravity = 0.0f;
        }
    } else {
        this->unk_1CA++;
    }

    Math_SmoothStepToF(&this->unk_1B0, 0.0f, 0.2f, 6.0f, 0.01f);

    this->unk_1D0++;
    if (ref_D_808BC000 < this->unk_1D0) {
        if ((gSaveContext.nextCutsceneIndex == 0xFFEF) && (ref_D_808BC000 < this->unk_1D0) &&
            (gSaveContext.nextCutsceneIndex == 0xFFEF)) {
            if (DOORWARP1_GET_FF00_1(&this->dyna.actor) != 0xFF) {
                play->nextEntrance = play->setupExitList[DOORWARP1_GET_FF00_3(&this->dyna.actor)];
                Scene_SetExitFade(play);
                play->transitionTrigger = TRANS_TRIGGER_START;
            } else {
                ref_func_80169FDC(play);
            }
        }
    }

    Math_StepToF(&this->unk_1A4, 2.0f, 0.01f);
    Math_StepToF(&this->unk_1A8, 10.0f, 0.02f);
    Lights_PointNoGlowSetInfo(&this->unk_1E0, player->actor.world.pos.x + 10, player->actor.world.pos.y + 10,
                              player->actor.world.pos.z + 10, 235, 255, 255, 255);
    Lights_PointNoGlowSetInfo(&this->unk_1F4, player->actor.world.pos.x - 10, player->actor.world.pos.y - 10,
                              player->actor.world.pos.z - 10, 235, 255, 255, 255);
    Math_SmoothStepToF(&this->dyna.actor.shape.yOffset, 0.0f, 0.5f, 2.0f, 0.1f);
}
