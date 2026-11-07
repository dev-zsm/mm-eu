// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_fire_tail.h"

u32 EffectSsFireTail_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsFireTailInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->vec = initParams->unk_14;
    this->velocity.x = 0.0f;
    this->velocity.y = 0.0f;
    this->velocity.z = 0.0f;
    this->accel.x = 0.0f;
    this->accel.y = 0.0f;
    this->accel.z = 0.0f;
    this->life = initParams->life;
    this->actor = initParams->actor;
    this->draw = EffectSsFireTail_Draw;
    this->update = EffectSsFireTail_Update;
    this->rScale = initParams->scale * 1000.0f;
    this->rLifespan = initParams->life;
    this->rReg2 = -10;
    this->rReg3 = -15;
    if (initParams->unk_20 == 0) {
        initParams->unk_20 = 1;
    }
    this->rReg10 = initParams->unk_20;
    this->rPrimColorR = initParams->primColor.r;
    this->rPrimColorG = initParams->primColor.g;
    this->rPrimColorB = initParams->primColor.b;
    this->rEnvColorR = initParams->envColor.r;
    this->rEnvColorG = initParams->envColor.g;
    this->rEnvColorB = initParams->envColor.b;
    this->rBodyPart = initParams->bodyPart;
    this->rType = initParams->type;

    return 1;
}
