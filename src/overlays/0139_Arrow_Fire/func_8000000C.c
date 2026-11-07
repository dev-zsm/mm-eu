// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arrow_fire.h"

void ArrowFire_Init(Actor* thisx, PlayState* play) {
    ArrowFire* this = (ArrowFire*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    this->radius = 0;
    this->height = 1.0f;
    ArrowFire_SetupAction(this, FireArrow_ChargeAndWait);
    Actor_SetScale(&this->actor, 0.01f);
    this->alpha = 160;
    this->timer = 0;
    this->screenFillIntensity = 0.0f;
    Collider_InitAndSetQuad(play, &this->collider1, &this->actor, &sQuadInit);
    Collider_InitAndSetQuad(play, &this->collider2, &this->actor, &sQuadInit);
}
