// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_a_keep_ctx.h"

void EnAObj_Init(Actor* thisx, PlayState* play) {
    EnAObj* this = (EnAObj*)thisx;

    this->actor.textId = AOBJ_GET_TEXTID(&this->actor);
    this->actor.params = AOBJ_GET_TYPE(&this->actor);
    Actor_ProcessInitChain(&this->actor, sInitChain);
    ActorShape_Init(&this->actor.shape, 0, ActorShadow_DrawCircle, 12);
    Collider_InitAndSetCylinder(play, &this->collision, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collision);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->actionFunc = EnAObj_Idle;
}
