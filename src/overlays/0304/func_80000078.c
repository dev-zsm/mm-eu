// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_en_ice_block.h"

u32 EffectEnIceBlock_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectEnIceBlockInitParams* params = PARAMS;

    Math_Vec3f_Copy(&this->pos, &params->pos);
    Math_Vec3f_Copy(&this->velocity, &params->velocity);
    Math_Vec3f_Copy(&this->accel, &params->accel);
    this->rScale = params->scale;
    this->rRot = Rand_ZeroOne() * 65535.0f;
    this->rRotVel = (s32)(Rand_ZeroOne() * 512.0f) + 0x400;
    this->life = 40;

    this->draw = EffectEnIceBlock_Draw;
    this->update = EffectEnIceBlock_Update;
    EffectEnIceBlock_CheckIceBlockObject(this, play);

    return 1;
}
