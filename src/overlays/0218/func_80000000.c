// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_ice_piece.h"

u32 EffectSsIcePiece_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsIcePieceInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->vec = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->life = initParams->life;
    this->draw = EffectSsIcePiece_Draw;
    this->update = EffectSsIcePiece_Update;
    this->rLifespan = initParams->life;
    this->rScale = initParams->scale * 100.0f;
    this->rYaw = Math_Atan2S_XY(initParams->velocity.z, initParams->velocity.x);
    this->rPitch = 0;
    this->rRotSpeed =
        ((fabsf(initParams->velocity.x) + fabsf(initParams->velocity.y)) * 100.0f) * (Rand_ZeroFloat(1.0f) + 0.5f);

    return 1;
}
