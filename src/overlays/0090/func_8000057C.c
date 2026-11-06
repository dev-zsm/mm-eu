// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void ref_func_808AEE3C(EnBombf* this, PlayState* play) {
    if (Actor_HasParent(&this->actor, play)) {
        this->unk_204 = 0.0f;
        EnBombf_SetupAction(this, ref_func_808AEF68);
        this->actor.room = -1;
        return;
    }

    this->unk_204 = 1.0f;
    if (!(this->actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
        Math_SmoothStepToF(&this->actor.speed, 0.0f, 1.0f, 0.025f, 0.0f);
        return;
    }

    Math_SmoothStepToF(&this->actor.speed, 0.0f, 1.0f, 1.5f, 0.0f);
    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
        Actor_PlaySfx_SurfaceBomb(play, &this->actor);
        if (this->actor.velocity.y < -6.0f) {
            this->actor.velocity.y *= -0.3f;
            this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
        }
    } else if (this->timer >= 4) {
        Actor_OfferCarry(&this->actor, play);
    }
}
