// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sibuki.h"

u32 EffectSsSibuki_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsSibukiInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;

    {
        TexturePtr tex = (KREG(2) != 0) ? gEffBubble2Tex : gEffBubble1Tex;

        this->gfx = (void*)OS_K0_TO_PHYSICAL(SEGMENTED_TO_K0(tex));
    }

    this->life = ((s32)((Rand_ZeroOne() * (500.0f + KREG(64))) * 0.01f)) + KREG(65) + 10;
    this->rMoveDelay = initParams->moveDelay + 1;
    this->draw = EffectSsSibuki_Draw;
    this->update = EffectSsSibuki_Update;
    this->rDirection = initParams->direction;
    this->rScale = initParams->scale;
    this->rPrimColorR = 100;
    this->rPrimColorG = 100;
    this->rPrimColorB = 100;
    this->rPrimColorA = 100;
    this->rEnvColorR = 255;
    this->rEnvColorG = 255;
    this->rEnvColorB = 255;
    this->rEnvColorA = 255;

    return 1;
}
