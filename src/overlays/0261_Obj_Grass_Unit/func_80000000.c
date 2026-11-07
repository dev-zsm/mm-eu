// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_unit.h"

s32 ObjGrassUnit_SpawnObjGrass(Actor* this, PlayState* play) {
    sGrassManager = (ObjGrass*)Actor_Spawn(&play->actorCtx, play, ACTOR_OBJ_GRASS, 0.0f, 0.0f, 0.0f, 0, 0, 0, -1);
    if (sGrassManager != NULL) {
        sGrassManager->actor.room = this->room;
        return true;
    }
    return false;
}
