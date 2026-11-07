// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

s32 ref_func_808FAA94(EnRr* this, PlayState* play) {
    ColliderCylinder* sp2C;
    s32 flag = (this->collider1.base.acFlags & AC_HIT) != 0;

    if (flag || (this->collider2.base.acFlags & AC_HIT)) {
        if (flag) {
            sp2C = &this->collider1;
        } else {
            sp2C = &this->collider2;
        }

        this->collider1.base.acFlags &= ~AC_HIT;
        this->collider2.base.acFlags &= ~AC_HIT;

        if ((this->drawDmgEffType == ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) &&
            (sp2C->elem.acHitElem->atDmgInfo.dmgFlags & 0xDB0B3)) {
            return false;
        }

        if (this->actor.colChkInfo.damageEffect == 14) {
            return false;
        }

        Actor_SetDropFlag(&this->actor, &sp2C->elem);
        ref_func_808FA4F4(this, play);
        ref_func_808FA19C(this, play);

        if (!Actor_ApplyDamage(&this->actor)) {
            Enemy_StartFinishingBlow(play, &this->actor);
            if (this->actor.colChkInfo.damageEffect == 3) {
                ref_func_808FA11C(this);
                this->collider1.base.acFlags &= ~AC_ON;
                this->collider2.base.acFlags &= ~AC_ON;
                ref_func_808FA9CC(this);
            } else {
                ref_func_808FA01C(this, play, sp2C);
                ref_func_808FA910(this);
            }
        } else if (this->actor.colChkInfo.damageEffect == 1) {
            Actor_PlaySfx(&this->actor, NA_SE_EN_COMMON_FREEZE);
            Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_BLUE, 255, COLORFILTER_BUFFLAG_OPA, 80);
            this->unk_1EE = 80;
            ref_func_808FA9CC(this);
        } else if (this->actor.colChkInfo.damageEffect == 3) {
            ref_func_808FA11C(this);
            ref_func_808FA9CC(this);
        } else {
            ref_func_808FA01C(this, play, sp2C);
            ref_func_808FA6B8(this);
        }
        return true;
    }
    return false;
}
