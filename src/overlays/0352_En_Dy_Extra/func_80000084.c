// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dy_extra.h"

void EnDyExtra_WaitForTrigger(EnDyExtra* this, PlayState* play) {
    Math_ApproachF(&this->actor.gravity, 0.0f, 0.1f, 0.005f);

    if (this->actor.world.pos.y < -85.0f) {
        this->actor.velocity.y = 0.0f;
    }

    if ((this->timer == 0) && this->trigger) {
        this->timer = 50;
        this->actionFunc = EnDyExtra_Fall;
    }
}
