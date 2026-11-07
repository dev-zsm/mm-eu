// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_SetupFlameMove(EnHonotrap* this) {
    f32 distInverse;

    this->actionFunc = EnHonotrap_FlameMove;
    distInverse = 1.0f / (Actor_WorldDistXYZToPoint(&this->actor, &this->targetPos) + 1.0f);
    this->actor.velocity.x = (this->targetPos.x - this->actor.world.pos.x) * distInverse;
    this->actor.velocity.y = (this->targetPos.y - this->actor.world.pos.y) * distInverse;
    this->actor.velocity.z = (this->targetPos.z - this->actor.world.pos.z) * distInverse;
    this->speedMod = 0.0f;
    this->timer = 160;
}
