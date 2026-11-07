// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FB794(EnRr* this, PlayState* play) {
    Vec3f sp2C;

    if ((this->actor.depthInWater < this->collider1.dim.height) && (this->actor.depthInWater > 1.0f) &&
        ((play->gameplayFrames % 9) == 0)) {
        sp2C.x = this->actor.world.pos.x;
        sp2C.y = this->actor.world.pos.y + this->actor.depthInWater;
        sp2C.z = this->actor.world.pos.z;
        EffectSsGRipple_Spawn(play, &sp2C, this->actor.scale.x * 34210.527f, this->actor.scale.x * 60526.316f, 0);
    }
}
