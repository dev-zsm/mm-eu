// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_SetChainXZ(ObjMine* this) {
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    f32 invLength = 1.0f / (ATTACH_OFFSET + (linkCount * LINK_SIZE));
    f32 dx = this->actor.world.pos.x - this->actor.home.pos.x;
    f32 dz = this->actor.world.pos.z - this->actor.home.pos.z;

    this->chain.air.displacement.x = dx * invLength;
    this->chain.air.displacement.z = dz * invLength;
}
