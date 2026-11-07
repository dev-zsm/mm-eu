// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_AirWater_SpawnBomb(ObjMine* this, PlayState* play) {
    f32 x = this->collider.elements[0].dim.worldSphere.center.x;
    f32 y = this->collider.elements[0].dim.worldSphere.center.y - BOMB_SPAWN_OFFSET;
    f32 z = this->collider.elements[0].dim.worldSphere.center.z;
    EnBom* bomb = (EnBom*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOM, x, y, z, 0, 0, 0, BOMB_TYPE_BODY);

    if (bomb != NULL) {
        bomb->timer = 0;
    }
}
