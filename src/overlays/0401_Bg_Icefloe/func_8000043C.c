// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icefloe.h"

void ref_func_80AC4D2C(BgIcefloe* this, PlayState* play) {
    this->timer--;
    if ((this->timer >= 38) && !(this->timer % 2)) {
        Vec3f velocity;
        Vec3f position;

        velocity.y = (this->timer - 38) * (1 / 12.0f);
        velocity.x = Rand_CenteredFloat(1.5f) * velocity.y;
        velocity.z = Rand_CenteredFloat(1.5f) * velocity.y;
        velocity.y += 0.8f;
        position.x = this->dyna.actor.world.pos.x + (2.0f * velocity.x);
        position.z = this->dyna.actor.world.pos.z + (2.0f * velocity.z);
        position.y = this->dyna.actor.world.pos.y + 3.0f;
        EffectSsIceSmoke_Spawn(play, &position, &velocity, &gZeroVec3f, 200);
    }
    if (this->timer < 25) {
        this->dyna.actor.scale.x -= 0.0052f;
        this->dyna.actor.scale.z -= 0.0052f;
    }
    this->dyna.actor.scale.y -= 0.0026f;
    if (this->dyna.actor.scale.y <= 0.0f) {
        Actor_Kill(&this->dyna.actor);
    }
}
