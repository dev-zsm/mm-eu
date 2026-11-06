// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hamishi.h"

void ref_func_809A13A0(ObjHamishi* this, PlayState* play) {
    s32 pad;
    Vec3f sp28;
    s32 bgId;

    sp28.x = this->actor.world.pos.x;
    sp28.y = this->actor.world.pos.y + 30.0f;
    sp28.z = this->actor.world.pos.z;

    this->actor.floorHeight =
        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp28);
}
