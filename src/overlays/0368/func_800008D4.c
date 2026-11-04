// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_SetWorld(ObjMine* this) {
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    f32 chainLength = ATTACH_OFFSET + (linkCount * LINK_SIZE);

    this->actor.world.pos.x = (this->chain.air.basis.y.x * -chainLength) + this->actor.home.pos.x;
    this->actor.world.pos.y = (this->chain.air.basis.y.y * -chainLength) + this->actor.home.pos.y;
    this->actor.world.pos.z = (this->chain.air.basis.y.z * -chainLength) + this->actor.home.pos.z;
}
