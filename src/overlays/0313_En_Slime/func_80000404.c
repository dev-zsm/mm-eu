// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Idle(EnSlime* this, PlayState* play) {
    f32 timerFactor;
    f32 scale;

    this->timer--;
    timerFactor = sqrtf(this->timer) * 0.2f;
    EnSlime_Blink(this);

    scale = ((Math_SinF(this->timer * (2 * M_PIf / 5)) * (0.13f * timerFactor)) + 1.0f) * 0.01f;
    this->actor.scale.x = scale;
    this->actor.scale.z = scale;
    if (this->timer < 24) {
        this->actor.scale.y = ((Math_CosF(this->timer * (2 * M_PIf / 5)) * (0.05f * timerFactor)) + 1.0f) * 0.01f;
    }

    this->actor.shape.rot.x = Rand_CenteredFloat(0x200) * timerFactor;
    this->actor.shape.rot.z = Rand_CenteredFloat(0x200) * timerFactor;

    
    
    if ((Player_GetMask(play) != PLAYER_MASK_STONE) && (this->actor.xzDistToPlayer < 280.0f) &&
        Actor_IsFacingPlayer(&this->actor, 0x5000)) {
        EnSlime_SetupTurnToPlayer(this);
    } else if (this->timer == 0) {
        
        EnSlime_SetupMoveInDirection(this);
    }
}
