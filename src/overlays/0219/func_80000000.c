// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_ice.h"

u32 EffectSsEnIce_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsEnIceInitParams* initParams = PARAMS;

    if (initParams->type == ENICE_TYPE_FLYING) {
        Math_Vec3f_Copy(&this->pos, &initParams->pos);

        if (initParams->actor != NULL) {
            Math_Vec3f_Diff(&this->pos, &initParams->actor->world.pos, &this->vec);
        } else {
            Math_Vec3f_Copy(&this->vec, &initParams->pos);
        }

        Math_Vec3f_Copy(&this->velocity, &gZeroVec3f);
        Math_Vec3f_Copy(&this->accel, &gZeroVec3f);
        this->life = 10;
        this->actor = initParams->actor;
        this->draw = EffectSsEnIce_Draw;
        this->update = EffectSsEnIce_UpdateFlying;
        this->rScale = initParams->scale * 100.0f;
        this->rPrimColorR = initParams->primColor.r;
        this->rPrimColorG = initParams->primColor.g;
        this->rPrimColorB = initParams->primColor.b;
        this->rPrimColorA = initParams->primColor.a;
        this->rEnvColorR = initParams->envColor.r;
        this->rEnvColorG = initParams->envColor.g;
        this->rEnvColorB = initParams->envColor.b;
        this->rAlphaMode = 1;
        this->rPitch = Rand_CenteredFloat(0x10000);
    } else if (initParams->type == ENICE_TYPE_NORMAL) {
        Math_Vec3f_Copy(&this->pos, &initParams->pos);
        Math_Vec3f_Copy(&this->vec, &initParams->pos);
        Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
        Math_Vec3f_Copy(&this->accel, &initParams->accel);
        this->life = initParams->life;
        this->draw = EffectSsEnIce_Draw;
        this->update = EffectSsEnIce_Update;
        this->rLifespan = initParams->life;
        this->rScale = initParams->scale * 100.0f;
        this->rYaw = Math_Atan2S_XY(initParams->velocity.z, initParams->velocity.x);
        this->rPitch = 0;
        this->rPrimColorR = initParams->primColor.r;
        this->rPrimColorG = initParams->primColor.g;
        this->rPrimColorB = initParams->primColor.b;
        this->rPrimColorA = initParams->primColor.a;
        this->rEnvColorR = initParams->envColor.r;
        this->rEnvColorG = initParams->envColor.g;
        this->rEnvColorB = initParams->envColor.b;
        this->rAlphaMode = 0;
    } else {
        return 0;
    }

    return 1;
}
