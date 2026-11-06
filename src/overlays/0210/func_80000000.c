// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_stick.h"

u32 EffectSsStick_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsStickInitParams* initParams = PARAMS;
    Vec3f pos;

    this->rObjectSlot = Object_GetSlot(&play->objectCtx, GAMEPLAY_KEEP);
    pos = initParams->pos;
    this->pos = pos;
    this->vec = pos;
    this->rYaw = initParams->yaw;
    this->velocity.x = Math_SinS(initParams->yaw) * 6.0f;
    this->velocity.z = Math_CosS(initParams->yaw) * 6.0f;
    this->life = 20;
    this->draw = EffectSsStick_Draw;
    this->update = EffectSsStick_Update;
    this->velocity.y = 26.0f;
    this->accel.y = -4.0f;
    return 1;
}
