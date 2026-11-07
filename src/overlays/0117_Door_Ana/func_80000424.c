// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_ana.h"

void DoorAna_GrabLink(DoorAna* this, PlayState* play) {
    Player* player;
    s8 pad[2];

    if (CutsceneManager_GetCurrentCsId() != this->actor.csId) {
        if (CutsceneManager_IsNext(this->actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        } else {
            CutsceneManager_Queue(this->actor.csId);
        }
    }

    if ((this->actor.playerHeightRel <= 0.0f) && (this->actor.xzDistToPlayer > 20.0f)) {
        player = GET_PLAYER(play);
        player->actor.world.pos.x = this->actor.world.pos.x + Math_SinS(this->actor.yawTowardsPlayer) * 20.0f;
        player->actor.world.pos.z = this->actor.world.pos.z + Math_CosS(this->actor.yawTowardsPlayer) * 20.0f;
    }
}
