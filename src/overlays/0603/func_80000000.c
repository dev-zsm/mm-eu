// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_dharma.h"

void BgIkanaDharma_SpawnEffects(BgIkanaDharma* this, PlayState* play) {
    s32 pad;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s32 i;
    f32 initialRadius = this->dyna.actor.scale.x * 200.0f;
    f32 initialY = this->dyna.actor.scale.y * 50.0f;

    for (i = 0; i < 4; i++) {
        f32 speed = (Rand_ZeroOne() * 5.0f) + 5.0f;
        s16 angle = (Rand_Next() >> 0x12) + this->dyna.actor.world.rot.y + 0x6000;
        f32 dirX = Math_SinS(angle);
        f32 dirZ = Math_CosS(angle);

        pos.x = (dirX * initialRadius) + this->dyna.actor.world.pos.x;
        pos.y = this->dyna.actor.world.pos.y + initialY;
        pos.z = (dirZ * initialRadius) + this->dyna.actor.world.pos.z;
        velocity.x = speed * dirX;
        velocity.y = Rand_ZeroOne() + 0.5f;
        velocity.z = speed * dirZ;
        accel.x = velocity.x * -0.05f;
        accel.y = -0.15f;
        accel.z = velocity.z * -0.05f;
        EffectSsKirakira_SpawnSmallYellow(play, &pos, &velocity, &accel);
    }
}
