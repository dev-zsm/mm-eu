// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_ripple.h"

void EffectSsGRipple_Update(PlayState* play, u32 index, EffectSs* this) {
    f32 radius;
    f32 primAlpha;
    f32 envAlpha;
    WaterBox* waterBox;
    s32 bgId;

    this->rWaterBoxNum = BgCheck_FindWaterBox(play, &play->colCtx, &this->pos, 3.0f, &waterBox, &bgId);
    this->rBgId = bgId;

    if (DECR(this->rLifespan) == 0) {
        radius = this->rRadius;
        Math_SmoothStepToF(&radius, this->rRadiusMax, 0.2f, 30.0f, 1.0f);
        this->rRadius = radius;

        primAlpha = this->rPrimColorA;
        envAlpha = this->rEnvColorA;

        Math_SmoothStepToF(&primAlpha, 0.0f, 0.2f, 15.0f, 7.0f);
        Math_SmoothStepToF(&envAlpha, 0.0f, 0.2f, 15.0f, 7.0f);

        this->rPrimColorA = primAlpha;
        this->rEnvColorA = envAlpha;
    }
}
