// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

ObjOshihiki* ObjOshihiki_GetBlockUnder(ObjOshihiki* this, PlayState* play) {
    DynaPolyActor* dyna;

    if ((this->floorBgIds[this->highestFloor] != BGCHECK_SCENE) &&
        (fabsf(this->dyna.actor.floorHeight - this->dyna.actor.world.pos.y) < 0.001f)) {
        dyna = DynaPoly_GetActor(&play->colCtx, this->floorBgIds[this->highestFloor]);
        if ((dyna != NULL) && (dyna->actor.id == ACTOR_OBJ_OSHIHIKI)) {
            return (ObjOshihiki*)dyna;
        }
    }
    return NULL;
}
