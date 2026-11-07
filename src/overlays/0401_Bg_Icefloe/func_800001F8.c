// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icefloe.h"

void BgIcefloe_Grow(BgIcefloe* this, PlayState* play) {
    Vec3f velocity;
    Vec3f position;

    velocity.x = Rand_CenteredFloat(6.0f);
    velocity.z = Rand_CenteredFloat(6.0f);
    velocity.y = Rand_ZeroFloat(4.0f) + 4.0f;
    this->dyna.actor.scale.x += (0.65f * 0.01f);
    this->dyna.actor.scale.z += (0.65f * 0.01f);
    this->dyna.actor.scale.y += (0.65f * 0.01f);
    position.x = this->dyna.actor.world.pos.x + (velocity.x * this->dyna.actor.scale.x * 75.0f);
    position.z = this->dyna.actor.world.pos.z + (velocity.z * this->dyna.actor.scale.z * 75.0f);
    position.y = this->dyna.actor.world.pos.y + (300.0f * this->dyna.actor.scale.y);
    EffectSsIceBlock_Spawn(play, &position, &velocity, &sIceBlockAccel, Rand_S16Offset(10, 10));
    this->timer--;
    if (this->timer == 0) {
        ref_func_80AC4C18(this);
    }
}
