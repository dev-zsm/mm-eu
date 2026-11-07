// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_ReactToBluntHit(EnSlime* this, PlayState* play) {
    f32 timerFactor;
    f32 scale;

    EnSlime_Blink(this);
    this->timer--;
    Math_StepToF(&this->actor.speed, 0.0f, 1.0f);
    timerFactor = sqrtf(this->timer);
    if (this->timer < 30) {
        scale = ((Math_CosF(this->timer * (2 * M_PIf / 5)) * (0.08f * timerFactor)) + 1.0f) * 0.01f;
        this->actor.scale.x = scale;
        this->actor.scale.z = scale;
    }
    if (this->timer == 15) {
        this->collider.base.acFlags |= AC_ON;
    }
    this->actor.scale.y = ((Math_SinF((f32)this->timer * (2 * M_PIf / 5)) * (0.07f * timerFactor)) + 1.0f) * 0.01f;
    this->actor.shape.rot.x = Rand_CenteredFloat(0x200) * timerFactor;
    this->actor.shape.rot.z = Rand_CenteredFloat(0x200) * timerFactor;

    if (this->timer == 0) {
        if (Actor_WorldDistXZToPoint(&this->actor, &this->actor.home.pos) > this->distLimit) {
            EnSlime_SetupMoveToHome(this);
        } else if ((this->actor.xzDistToPlayer < 280.0f) && (Player_GetMask(play) != PLAYER_MASK_STONE)) {
            EnSlime_SetupTurnToPlayer(this);
        } else {
            EnSlime_SetupIdle(this);
        }
    }
}
