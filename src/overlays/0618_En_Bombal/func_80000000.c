// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombal.h"

void EnBombal_Init(Actor* thisx, PlayState* play) {
    EnBombal* this = (EnBombal*)thisx;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    this->actor.colChkInfo.mass = 0;
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->actor.attentionRangeType = ATTENTION_RANGE_6;
    this->actor.colChkInfo.health = 1;
    this->scale = 0.1f;
    this->csId = this->actor.csId;
    ref_func_80C05B24(this);
}
