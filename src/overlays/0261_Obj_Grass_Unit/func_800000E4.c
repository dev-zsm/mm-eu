// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_unit.h"

s32 ObjGrassUnit_SpawnObjGrassCarry1(Actor* this, PlayState* play) {
    sGrassCarry1 =
        (ObjGrassCarry*)Actor_Spawn(&play->actorCtx, play, ACTOR_OBJ_GRASS_CARRY, 0.0f, 0.0f, 0.0f, 0, 0, 0, 1);
    if (sGrassCarry1 != NULL) {
        sGrassCarry1->actor.room = this->room;
        return true;
    }
    return false;
}
