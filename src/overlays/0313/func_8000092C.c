// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_MoveToHome(EnSlime* this, PlayState* play) {
    f32 timerFactor;

    EnSlime_Blink(this);
    this->timer--;
    Math_ApproachS(&this->actor.shape.rot.y, this->idleRotY, 4, 0x400);
    if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
        
        this->idleRotY = this->actor.wallYaw;
    } else {
        this->idleRotY = Actor_WorldYawTowardPoint(&this->actor, &this->actor.home.pos);
    }

    timerFactor = fabsf(Math_SinF(this->timer * (M_PIf / 24)));
    Math_StepToF(&this->actor.scale.z, ((0.15f * timerFactor) + 1.0f) * 0.01f, 0.0002f);
    Math_StepToF(&this->actor.scale.x, (1.0f - (0.2f * timerFactor)) * 0.01f, 0.0002f);
    Math_StepToF(&this->actor.scale.y, (1.0f - (0.1f * timerFactor)) * 0.01f, 0.0002f);

    this->actor.speed = (0.8f * timerFactor) + 0.2f;
    this->actor.shape.rot.x = 0x800 * timerFactor;
    this->actor.world.rot.y = this->actor.shape.rot.y;

    
    if (this->timer == 0) {
        this->timer = 24;
    }

    
    if (Actor_WorldDistXZToPoint(&this->actor, &this->actor.home.pos) < (this->distLimit * 0.8f)) {
        EnSlime_SetupIdle(this);
    }
}
