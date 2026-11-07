// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_shutter.h"

void ref_func_80ACAEF0(BgOpenShutter* this, PlayState* play) {
    s32 pad;
    s16 quakeIndex;

    Math_StepToF(&this->slidingDoor.dyna.actor.velocity.y, 20.0f, 8.0f);
    if (Math_StepToF(&this->slidingDoor.dyna.actor.world.pos.y, this->slidingDoor.dyna.actor.home.pos.y,
                     this->slidingDoor.dyna.actor.velocity.y)) {
        this->slidingDoor.dyna.actor.floorHeight = this->slidingDoor.dyna.actor.home.pos.y;
        Actor_SpawnFloorDustRing(play, &this->slidingDoor.dyna.actor, &this->slidingDoor.dyna.actor.world.pos, 60.0f,
                                 10, 8.0f, 500, 10, true);
        Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_BIGWALL_BOUND);

        quakeIndex = Quake_Request(Play_GetCamera(play, CAM_ID_MAIN), QUAKE_TYPE_3);
        Quake_SetSpeed(quakeIndex, -32536);
        Quake_SetPerturbations(quakeIndex, 2, 0, 0, 0);
        Quake_SetDuration(quakeIndex, 10);

        Rumble_Request(this->slidingDoor.dyna.actor.xyzDistToPlayerSq, 180, 20, 100);

        this->slidingDoor.unk_15C = 0;
        this->actionFunc = ref_func_80ACAD88;
    }
}
