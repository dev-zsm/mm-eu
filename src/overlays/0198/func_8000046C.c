// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kirakira.h"

void ref_func_80977E6C(PlayState* play, u32 index, EffectSs* this) {
    this->velocity.x *= 0.95f;
    this->velocity.z *= 0.95f;
    this->accel.x = Rand_CenteredFloat(0.2f);
    this->accel.z = Rand_CenteredFloat(0.2f);
    this->rEnvColorA += this->rAlphaStep;

    if (this->rEnvColorA < 0) {
        this->rEnvColorA = 0;
        this->rAlphaStep = -this->rAlphaStep;
    } else if (this->rEnvColorA > 255) {
        this->rEnvColorA = 255;
        this->rAlphaStep = -this->rAlphaStep;
    }

    this->rYaw += this->rRotSpeed;
}
