// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_rot.h"

void BgCtowerRot_DoorIdle(BgCtowerRot* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f offset;

    Actor_WorldToActorCoords(&this->dyna.actor, &offset, &player->actor.world.pos);
    if (offset.z > 30.0f) {
        this->unk160 = 0.0f;
        CutsceneManager_Queue(this->dyna.actor.csId);
        this->actionFunc = BgCtowerRot_SetupDoorClose;
    }
}
