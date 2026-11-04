// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gamelupy.h"

void EnGamelupy_SpawnSparkles(EnGamelupy* this, PlayState* play) {
    Vec3f pos;
    Vec3f accel;
    Vec3f velocity;

    pos = this->actor.world.pos;
    velocity.x = Math_SinS(this->sparklesAngle) * 3.0f;
    velocity.y = 5.5f;
    velocity.z = Math_CosS(this->sparklesAngle) * 3.0f;
    accel.x = -0.05f * velocity.x;
    accel.y = -0.4f;
    accel.z = -0.05f * velocity.z;
    EffectSsKirakira_SpawnDispersed(play, &pos, &velocity, &accel, &sPrimColor, &sEnvColor, 3000, 40);
    this->sparklesAngle += this->sparklesAngleStep;
}
