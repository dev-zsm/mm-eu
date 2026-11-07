// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808BAAF4(DoorWarp1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 csId;
    f32 phi_f2;

    phi_f2 = 200.0f;
    if (play->sceneId == SCENE_SEA) {
        phi_f2 = 85.0f;
    }

    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_86_80) && (fabsf(this->dyna.actor.xzDistToPlayer) < phi_f2) &&
        ((player->actor.world.pos.y - 20.0f) < this->dyna.actor.world.pos.y) &&
        (this->dyna.actor.world.pos.y < (player->actor.world.pos.y + 20.0f))) {
        csId = this->dyna.actor.csId;

        if (CutsceneManager_IsNext(csId)) {
            CutsceneManager_Start(csId, &this->dyna.actor);
            SET_WEEKEVENTREG(WEEKEVENTREG_86_80);
            DoorWarp1_SetupAction(this, ref_func_808BABF4);
        } else {
            CutsceneManager_Queue(csId);
        }
    }
}
