// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_MoveInDirection(EnSlime* this, PlayState* play) {
    f32 sinFactor;

    EnSlime_Blink(this);
    this->timer--;
    Math_ApproachS(&this->actor.shape.rot.y, this->idleRotY, 4, 0x100);

    
    
    if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
        this->idleRotY = this->actor.wallYaw;
    } else if (Actor_WorldDistXZToPoint(&this->actor, &this->actor.home.pos) > 120.0f) {
        this->idleRotY = Actor_WorldYawTowardPoint(&this->actor, &this->actor.home.pos);
    }

    
    sinFactor = fabsf(Math_SinF(this->timer * (M_PIf / 24)));
    Math_StepToF(&this->actor.scale.z, ((0.15f * sinFactor) + 1.0f) * 0.01f, 0.0002f);
    Math_StepToF(&this->actor.scale.x, (1.0f - (0.2f * sinFactor)) * 0.01f, 0.0002f);
    Math_StepToF(&this->actor.scale.y, (1.0f - (0.1f * sinFactor)) * 0.01f, 0.0002f);

    this->actor.speed = (0.8f * sinFactor) + 0.2f;
    this->actor.shape.rot.x = 0x800 * sinFactor;
    this->actor.world.rot.y = this->actor.shape.rot.y;

    if (Actor_WorldDistXZToPoint(&this->actor, &this->actor.home.pos) > this->distLimit) {
        
        EnSlime_SetupMoveToHome(this);
    } else if ((Player_GetMask(play) != PLAYER_MASK_STONE) && (this->actor.xzDistToPlayer < 280.0f) &&
               Actor_IsFacingPlayer(&this->actor, 0x5000)) {
        
        
        EnSlime_SetupTurnToPlayer(this);
    } else if (this->timer == 0) {
        
        EnSlime_SetupIdle(this);
    }
}
