// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_bubble.h"

u32 EffectSsBubble_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsBubbleInitParams* initParams = (EffectSsBubbleInitParams*)initParamsx;

    {
        TexturePtr tex = (Rand_ZeroOne() < 0.5f) ? gEffBubble1Tex : gEffBubble2Tex;

        this->gfx = (void*)OS_K0_TO_PHYSICAL(SEGMENTED_TO_K0(tex));
    }

    this->pos.x = ((Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.x;
    this->pos.y = (((Rand_ZeroOne() - 0.5f) * initParams->yPosRandScale) + initParams->yPosOffset) + initParams->pos.y;
    this->pos.z = ((Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.z;
    Math_Vec3f_Copy(&this->vec, &this->pos);
    this->life = 1;
    this->rScale = (((Rand_ZeroOne() * 0.5f) + 1.0f) * initParams->scale) * 100.0f;
    this->draw = EffectSsBubble_Draw;
    this->update = EffectSsBubble_Update;

    return 1;
}
