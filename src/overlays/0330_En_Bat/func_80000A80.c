// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_SetupDie(EnBat* this, PlayState* play) {
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    Enemy_StartFinishingBlow(play, &this->actor);
    this->actor.speed *= Math_CosS(this->actor.world.rot.x);
    this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
    this->actor.velocity.y = 0.0f;
    Actor_PlaySfx(&this->actor, NA_SE_EN_FFLY_DEAD);

    if (this->actor.colChkInfo.damageEffect == BAD_BAT_DMGEFF_ICE) {
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX;
        this->drawDmgEffAlpha = 1.0f;
        this->drawDmgEffFrozenSteamScale = 60.0f * (0.45f / 40.0f);
        this->drawDmgEffScale = 0.45f;
    } else if (this->actor.colChkInfo.damageEffect == BAD_BAT_DMGEFF_LIGHT) {
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_LIGHT_ORBS;
        this->drawDmgEffAlpha = 4.0f;
        this->drawDmgEffScale = 0.45f;
        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, this->collider.elem.acDmgInfo.hitPos.x,
                    this->collider.elem.acDmgInfo.hitPos.y, this->collider.elem.acDmgInfo.hitPos.z, 0, 0, 0,
                    CLEAR_TAG_PARAMS(CLEAR_TAG_SMALL_LIGHT_RAYS));
    } else if (this->actor.colChkInfo.damageEffect == BAD_BAT_DMGEFF_FIRE) {
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_FIRE;
        this->drawDmgEffAlpha = 4.0f;
        this->drawDmgEffScale = 0.45f;
    }

    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_OPA, 40);

    if (this->actor.flags & ACTOR_FLAG_ATTACHED_TO_ARROW) {
        this->actor.speed = 0.0f;
    }

    this->collider.base.acFlags &= ~AC_ON;
    this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    this->actionFunc = EnBat_Die;
}
