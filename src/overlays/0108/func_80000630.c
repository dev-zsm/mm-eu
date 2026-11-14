// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_80000630(DemoEffect* this, PlayState* play) {
    Actor_SetScale(&this->actor, this->actor.scale.x - 0.02f);

    this->timer++;
    if (this->actor.scale.x < 0.02f) {
        Actor_Kill(&this->actor);
    }
}
