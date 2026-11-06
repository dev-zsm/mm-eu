// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_solder_srch_ball.h"

u32 EffectSsSolderSrchBall_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsSolderSrchBallInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->update = EffectSsSolderSrchBall_Update;
    if (!(initParams->flags & SOLDERSRCHBALL_INVISIBLE)) {
        this->draw = EffectSsSolderSrchBall_Draw;
    }
    this->life = 10;
    this->rgScale = initParams->scale;
    this->rFlags = initParams->flags;

    
    
    
    this->actor = (Actor*)initParams->playerDetected;
    return 1;
}
