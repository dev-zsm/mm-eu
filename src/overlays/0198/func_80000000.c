// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kirakira.h"

u32 EffectSsKirakira_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsKirakiraInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;

    if ((this->life = initParams->life) < 0) {
        this->life = -this->life;
        this->gfx = gEffSparklesDL;
        this->update = ref_func_80977F28;
        this->rEnvColorA = initParams->scale;
        this->rScale = 0;
    } else {
        this->gfx = gEffSparklesDL;

        if (initParams->updateMode == 0) {
            this->update = ref_func_80977DB4;
        } else {
            this->update = ref_func_80977E6C;
        }

        this->rEnvColorA = initParams->envColor.a;
        this->rScale = initParams->scale;
        if (this->rScale < 0) {
            this->gfx = gameplay_keep_DL_06A800;
            this->rScale = -this->rScale;
        }
    }

    this->draw = EffectSsKirakira_Draw;
    this->rRotSpeed = initParams->rotSpeed;
    this->rYaw = initParams->yaw;
    this->rPrimColorR = initParams->primColor.r;
    this->rPrimColorG = initParams->primColor.g;
    this->rPrimColorB = initParams->primColor.b;
    this->rPrimColorA = initParams->primColor.a;
    this->rEnvColorR = initParams->envColor.r;
    this->rEnvColorG = initParams->envColor.g;
    this->rEnvColorB = initParams->envColor.b;
    this->rAlphaStep = initParams->alphaStep;
    this->rLifespan = initParams->life;

    return 1;
}
