// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

s32 ref_func_80A5BA58(EnKusa2* this, PlayState* play) {
    Vec3f sp24;
    s32 bgId;

    sp24.x = this->actor.world.pos.x;
    sp24.y = this->actor.world.pos.y + 30.0f;
    sp24.z = this->actor.world.pos.z;
    this->actor.floorHeight =
        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp24);
    if (this->actor.floorHeight > BGCHECK_Y_MIN) {
        this->actor.floorBgId = bgId;
        this->actor.world.pos.y = this->actor.floorHeight;
        Math_Vec3f_Copy(&this->actor.home.pos, &this->actor.world.pos);
        return true;
    }
    return false;
}
