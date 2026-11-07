// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA01C(EnRr* this, PlayState* play, ColliderCylinder* collider) {
    if (this->actor.colChkInfo.damageEffect == 2) {
        this->drawDmgEffScale = 0.85f;
        this->drawDmgEffAlpha = 4.0f;
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_FIRE;
    } else if (this->actor.colChkInfo.damageEffect == 4) {
        this->drawDmgEffScale = 0.85f;
        this->drawDmgEffAlpha = 4.0f;
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_LIGHT_ORBS;
        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, collider->elem.acDmgInfo.hitPos.x,
                    collider->elem.acDmgInfo.hitPos.y, collider->elem.acDmgInfo.hitPos.z, 0, 0, 0,
                    CLEAR_TAG_PARAMS(CLEAR_TAG_LARGE_LIGHT_RAYS));
    } else if (this->actor.colChkInfo.damageEffect == 5) {
        this->drawDmgEffScale = 0.85f;
        this->drawDmgEffAlpha = 4.0f;
        this->drawDmgEffType = ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_SMALL;
    }
}
