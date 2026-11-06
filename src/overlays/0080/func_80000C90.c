// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBubble* this = (EnBubble*)thisx;

    ActorShape_Init(&this->actor.shape, 16.0f, ActorShadow_DrawCircle, 0.2f);
    Collider_InitJntSph(play, &this->colliderSphere);
    Collider_SetJntSph(play, &this->colliderSphere, &this->actor, &sJntSphInit, this->colliderElements);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, DamageTable_Get(9), &sColChkInfoInit);
    
    this->actor.hintId = TATL_HINT_ID_IGOS_DU_IKANA;
    this->bounceDirection.x = Rand_ZeroOne();
    this->bounceDirection.y = Rand_ZeroOne();
    this->bounceDirection.z = Rand_ZeroOne();
    EnBubble_Vec3fNormalize(&this->bounceDirection);
    this->velocityFromBounce.x = this->bounceDirection.x * 3.0f;
    this->velocityFromBounce.y = this->bounceDirection.y * 3.0f;
    this->velocityFromBounce.z = this->bounceDirection.z * 3.0f;
    EnBubble_SetDimensions(this, 0);
    this->actionFunc = EnBubble_Wait;
}
