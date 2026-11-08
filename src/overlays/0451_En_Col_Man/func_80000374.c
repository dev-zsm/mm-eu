// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void ref_func_80AFDFB4(EnColMan* this, PlayState* play) {
    static Color_RGBA8 sPrimColor = { 60, 50, 20, 255 };
    static Color_RGBA8 sEnvColor = { 40, 30, 30, 255 };
    s32 i;
    Vec3f velocity;
    Vec3f accel;

    this->scale = (BREG(55) / 10000.0f) + 0.0015f;

    if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) && (this->actor.velocity.y < 0.0f)) {
        if (!this->hasSetRandomValues) {
            this->actor.world.rot.y = Rand_CenteredFloat(30000.0f);
            this->actor.speed = 2.0f + BREG(56) + Rand_ZeroFloat(2.0f);
            this->actor.velocity.y = 12.0f + BREG(57) + Rand_ZeroFloat(5.0f);
            this->hasSetRandomValues = true;
            Actor_PlaySfx(&this->actor, NA_SE_EN_ANSATSUSYA_ROCK);
            return;
        }

        for (i = 0; i < 2; i++) {
            velocity.x = Rand_CenteredFloat(2.0f);
            velocity.y = Rand_ZeroFloat(2.0f) + 1.0f;
            velocity.z = Rand_CenteredFloat(2.0f);
            accel.y = -0.1f;
            accel.z = 0.0f;
            accel.x = 0.0f;

            ref_func_800B0EB0(play, &this->actor.world.pos, &velocity, &accel, &sPrimColor, &sEnvColor,
                          Rand_ZeroFloat(50.0f) + 60.0f, 30, Rand_ZeroFloat(5.0f) + 20.0f);
        }

        Actor_Kill(&this->actor);
    }
}
