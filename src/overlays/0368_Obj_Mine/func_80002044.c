// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_SetupExplode(ObjMine* this) {
    this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    this->actor.draw = ObjMine_DrawExplosion;
    this->actor.shape.shadowDraw = NULL;
    this->actor.scale.x = 0.02f;
    this->actor.scale.y = 0.02f;
    this->actor.scale.z = 0.02f;
    this->actionFunc = ObjMine_Explode;
}
