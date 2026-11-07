// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B3A498(ObjSnowball2* this) {
    this->actor.home.pos.x = this->actor.world.pos.x;
    this->unk_1AC = 46;
    this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    this->actor.home.pos.y = this->actor.world.pos.y + this->actor.depthInWater;
    this->actor.home.pos.z = this->actor.world.pos.z;
    this->actor.world.pos.y += this->actor.shape.yOffset * this->actor.scale.y;
    this->actor.shape.yOffset = 0.0f;
    this->actor.speed = 0.0f;
    this->actionFunc = ref_func_80B3A500;
}
