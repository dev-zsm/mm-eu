// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tsn.h"

void func_8000019C(Actor* thisx, PlayState* play) {
    EnTsn* this = (EnTsn*)thisx;

    if (ENTSN_IS_OBJECT(&this->actor)) {
        EnTsn_InitObject(this, play);
        return;
    }

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gFishermanSkel, &gFishermanIdleAnim, NULL, NULL, 0);
    Animation_PlayLoop(&this->skelAnime, &gFishermanIdleAnim);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->flags = 0;
    this->actionFunc = EnTsn_Fisherman_Idle;
    this->actor.textId = 0;
    this->actor.velocity.y = 0.0f;
    this->actor.terminalVelocity = -9.0f;
    this->actor.gravity = -1.0f;

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE)) {
        Actor_Kill(&this->actor);
    }
}
