// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sc_ruppe.h"

void EnScRuppe_Init(Actor* thisx, PlayState* play) {
    EnScRuppe* this = (EnScRuppe*)thisx;
    ColliderCylinder* collider = &this->collider;

    Collider_InitCylinder(play, collider);
    Collider_InitAndSetCylinder(play, collider, &this->actor, &sCylinderInit);
    Actor_SetScale(&this->actor, 0.03f);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 10.0f);
    this->ruppeIndex = SCRUPPE_GET_TYPE(thisx);
    if ((this->ruppeIndex < RUPEE_GREEN) || (this->ruppeIndex >= RUPEE_UNUSED)) {
        this->ruppeIndex = RUPEE_GREEN;
    }
    this->actor.speed = 0.0f;
    this->actionFunc = ref_func_80BD6A8C;
    this->actor.gravity = -0.5f;
    this->actor.shape.yOffset = 700.0f;
}
