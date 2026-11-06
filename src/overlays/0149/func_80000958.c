// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tubo_trap.h"

void EnTuboTrap_Levitate(EnTuboTrap* this, PlayState* play) {
    this->actor.shape.rot.y += 0x1388;
    Math_ApproachF(&this->actor.world.pos.y, this->targetHeight, 0.8f, 3.0f);

    if (fabsf(this->actor.world.pos.y - this->targetHeight) < 10.0f) {
        this->actor.speed = 10.0f;
        this->actor.world.rot.y = this->actor.yawTowardsPlayer;
        this->actionFunc = EnTuboTrap_FlyAtPlayer;
    }
}
