// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14F4C(ObjHakaisi* this, PlayState* play, s32 arg2) {
    if (!arg2) {
        Actor_Spawn(&play->actorCtx, play, ACTOR_OBJ_HAKAISI, this->dyna.actor.world.pos.x,
                    this->dyna.actor.world.pos.y + 55.0f, this->dyna.actor.world.pos.z - 10.0f,
                    this->dyna.actor.shape.rot.x, this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, 4);
    } else {
        Actor_Spawn(&play->actorCtx, play, ACTOR_OBJ_HAKAISI, this->dyna.actor.world.pos.x + 20.0f,
                    this->dyna.actor.world.pos.y + 30.0f, this->dyna.actor.world.pos.z - 10.0f,
                    this->dyna.actor.shape.rot.x, this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, 5);
    }
}
