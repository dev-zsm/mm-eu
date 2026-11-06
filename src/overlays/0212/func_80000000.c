// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_stone1.h"

u32 EffectSsStone1_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsStone1InitParams* initParams = PARAMS;
    Vec3f pos = initParams->pos;

    this->pos = pos;
    this->vec = pos;
    this->life = 8;
    this->rReg0 = initParams->reg0;
    this->draw = EffectSsStone1_Draw;
    this->update = EffectSsStone1_Update;

    return 1;
}
