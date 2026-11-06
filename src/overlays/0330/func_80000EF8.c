// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_UpdateDamage(EnBat* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;

        Actor_SetDropFlag(&this->actor, &this->collider.elem);
        this->collider.base.atFlags &= ~AT_ON;

        if (this->actionFunc == EnBat_DiveAttack) {
            sNumberAttacking--;
        }

        if (this->actor.colChkInfo.damageEffect == BAD_BAT_DMGEFF_ELECTRIC) {
            this->timer = 40;
            this->drawDmgEffType = ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_LARGE;
            this->drawDmgEffAlpha = 2.0f;
            this->drawDmgEffScale = 0.45f;
            EnBat_SetupStunned(this);
        } else if (this->actor.colChkInfo.damageEffect == BAD_BAT_DMGEFF_STUN) {
            this->timer = 40;
            EnBat_SetupStunned(this);
        } else {
            Actor_ApplyDamage(&this->actor);
            EnBat_SetupDie(this, play);
        }
    }
}
