// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_ice.h"

void EffectSsEnIce_UpdateFlying(PlayState* play, u32 index, EffectSs* this) {
    s16 rand;

    if ((this->actor != NULL) && (this->actor->update != NULL)) {
        if ((this->life >= 9) && (this->actor->colorFilterTimer != 0) && !(this->actor->colorFilterParams & 0xC000)) {
            Math_Vec3f_Sum(&this->actor->world.pos, &this->vec, &this->pos);
            this->life++;
        } else if (this->life == 9) {
            this->accel.x = Math_SinS(Math_Vec3f_Yaw(&this->actor->world.pos, &this->pos)) * (Rand_ZeroOne() + 1.0f);
            this->accel.z = Math_CosS(Math_Vec3f_Yaw(&this->actor->world.pos, &this->pos)) * (Rand_ZeroOne() + 1.0f);
            this->accel.y = -1.5f;
            this->velocity.y = 5.0f;
        }
    } else {
        this->actor = NULL;
        if (this->life >= 9) {
            rand = Rand_CenteredFloat(0xFFFF);
            this->accel.x = Math_SinS(rand) * (Rand_ZeroOne() + 1.0f);
            this->accel.z = Math_CosS(rand) * (Rand_ZeroOne() + 1.0f);
            this->life = 8;
            this->accel.y = -1.5f;
            this->velocity.y = 5.0f;
        }
    }
}
