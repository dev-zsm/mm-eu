// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B8C48(DoorWarp1* this, PlayState* play) {
    this->dyna.actor.shape.yOffset = 0.0f;
    Actor_SetScale(&this->dyna.actor, 0.1f);
    Lights_PointNoGlowSetInfo(&this->unk_1E0, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 200, 255, 255, 255);
    Lights_PointNoGlowSetInfo(&this->unk_1F4, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 200, 255, 255, 255);
    if (((DOORWARP1_GET_FF(&this->dyna.actor) == ENDOORWARP1_FF_2) && CHECK_QUEST_ITEM(QUEST_REMAINS_ODOLWA)) ||
        ((DOORWARP1_GET_FF(&this->dyna.actor) == ENDOORWARP1_FF_3) && CHECK_QUEST_ITEM(QUEST_REMAINS_GOHT)) ||
        ((DOORWARP1_GET_FF(&this->dyna.actor) == ENDOORWARP1_FF_4) && CHECK_QUEST_ITEM(QUEST_REMAINS_GYORG)) ||
        ((DOORWARP1_GET_FF(&this->dyna.actor) == ENDOORWARP1_FF_5) && CHECK_QUEST_ITEM(QUEST_REMAINS_TWINMOLD))) {
        s16 params = DOORWARP1_GET_FF00_2(&this->dyna.actor);

        params |= 6;
        Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, ACTOR_DOOR_WARP1, this->dyna.actor.world.pos.x,
                           this->dyna.actor.world.pos.y + 10.0f, this->dyna.actor.world.pos.z,
                           this->dyna.actor.world.rot.x, this->dyna.actor.world.rot.y, this->dyna.actor.world.rot.z,
                           params);
        DoorWarp1_SetupAction(this, ref_func_808BAAF4);
    } else {
        DoorWarp1_SetupAction(this, ref_func_808BABF4);
    }
}
