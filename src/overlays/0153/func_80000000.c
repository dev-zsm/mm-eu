// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80936CF0(ObjBean* this, PlayState* play) {
    Vec3f sp24;
    s32 bgId;

    sp24.x = this->dyna.actor.world.pos.x;
    sp24.y = this->dyna.actor.world.pos.y + 29.999998f;
    sp24.z = this->dyna.actor.world.pos.z;
    this->dyna.actor.floorHeight =
        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->dyna.actor.floorPoly, &bgId, &this->dyna.actor, &sp24);
}
