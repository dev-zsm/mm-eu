// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void EnMm_Init(Actor* thisx, PlayState* play) {
    EnMm* this = (EnMm*)thisx;
    EnMmActionFunc action;

    if ((this->actor.params >= 0) && (!CHECK_WEEKEVENTREG(WEEKEVENTREG_37_10) ||
                                      CHECK_WEEKEVENTREG(WEEKEVENTREG_37_08) || (gSaveContext.unk_1014 != 0))) {
        Actor_Kill(&this->actor);
        return;
    }
    Actor_ProcessInitChain(&this->actor, sInitChain);
    ActorShape_Init(&this->actor.shape, 50.0f, ActorShadow_DrawCircle, 1.2f);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    if (this->actor.parent != NULL) {
        ref_func_80965BBC(this);
        return;
    }
    if (this->actor.csId > CS_ID_NONE) {
        action = ref_func_80965D3C;
    } else {
        action = ref_func_80965DB4;
    }
    EnMm_SetupAction(this, action);
}
