// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

f32 ref_func_808A0D90(PlayState* play, DoorShutter* this, f32 arg2, f32 arg3, f32 arg4) {
    Player* player = GET_PLAYER(play);
    Vec3f sp28;
    Vec3f sp1C;

    sp28.x = player->actor.world.pos.x;
    sp28.y = player->actor.world.pos.y + arg2;
    sp28.z = player->actor.world.pos.z;

    Actor_WorldToActorCoords(&this->slidingDoor.dyna.actor, &sp1C, &sp28);

    if ((arg3 < fabsf(sp1C.x)) || (arg4 < fabsf(sp1C.y))) {
        return FLT_MAX;
    }
    return sp1C.z;
}
