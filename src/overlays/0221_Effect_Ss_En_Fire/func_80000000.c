// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_fire.h"

u32 EffectSsEnFire_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsEnFireInitParams* initParams = PARAMS;

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &gZeroVec3f);
    Math_Vec3f_Copy(&this->accel, &gZeroVec3f);
    this->life = 20;
    this->rLifespan = this->life;
    this->actor = initParams->actor;
    this->rScroll = Rand_ZeroOne() * 20.0f;
    this->draw = EffectSsEnFire_Draw;
    this->update = EffectSsEnFire_Update;
    this->rUnused = -15;

    if (initParams->bodyPart <= BODYPART_NONE) {
        this->rYaw = Math_Vec3f_Yaw(&initParams->actor->world.pos, &initParams->pos) - initParams->actor->shape.rot.y;
        this->rPitch =
            Math_Vec3f_Pitch(&initParams->actor->world.pos, &initParams->pos) - initParams->actor->shape.rot.x;
        this->vec.z = Math_Vec3f_DistXYZ(&initParams->pos, &initParams->actor->world.pos);
    }

    this->rScaleMax = initParams->scale;

    if (initParams->params & ENFIRE_PARAM_USE_SCALE) {
        this->rScale = initParams->scale;
    } else {
        this->rScale = 0;
    }

    this->rReg6 = initParams->params & 0x7FFF;
    this->rBodyPart = initParams->bodyPart;
    this->rFlags = initParams->flags;

    return 1;
}
