// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_UpdateDamage(EnSlime* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;

        if ((this->drawDmgEffType != ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) ||
            !(this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0xDB0B3)) {

            EnSlime_Thaw(this, play);
            if ((this->actor.params == EN_SLIME_TYPE_BLUE) &&
                (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_FREEZE)) {
                
                this->actor.colChkInfo.damage = 0;
            }

            if (Actor_ApplyDamage(&this->actor) == 0) {
                Actor_SetDropFlag(&this->actor, &this->collider.elem);
                Enemy_StartFinishingBlow(play, &this->actor);
                this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
            }

            if (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_BLUNT) {
                EnSlime_SetupReactToBluntHit(this);
            } else if (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_STUN) {
                this->timer = 40;
                Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_BLUE, 255, COLORFILTER_BUFFLAG_XLU, 40);
                Actor_PlaySfx(&this->actor, NA_SE_EN_COMMON_FREEZE);
                EnSlime_SetupStun(this);
            } else if (this->actor.colChkInfo.damageEffect != EN_SLIME_DMGEFF_HOOKSHOT) {
                if (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_FREEZE) {
                    if (this->actor.params == EN_SLIME_TYPE_BLUE) {
                        EnSlime_SetupSpawnIceBlock(this);
                    } else {
                        EnSlime_Freeze(this);
                        if (this->actor.colChkInfo.health == 0) {
                            this->timer = 3;
                            this->collider.base.acFlags &= ~AC_ON;
                        }
                        EnSlime_SetupStun(this);
                    }
                } else {
                    if (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_LIGHT) {
                        this->drawDmgEffAlpha = 4.0f;
                        this->drawDmgEffScale = 0.4f;
                        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_LIGHT_ORBS;
                        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, this->collider.elem.acDmgInfo.hitPos.x,
                                    this->collider.elem.acDmgInfo.hitPos.y, this->collider.elem.acDmgInfo.hitPos.z, 0,
                                    0, 0, CLEAR_TAG_PARAMS(CLEAR_TAG_LARGE_LIGHT_RAYS));
                    } else if (this->actor.colChkInfo.damageEffect == EN_SLIME_DMGEFF_ELECTRIC) {
                        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_LARGE;
                        this->drawDmgEffAlpha = 4.0f;
                        this->drawDmgEffScale = 0.4f;
                    }
                    EnSlime_SetupDamaged(this, play, true);
                }
            }
        }
    }
}
