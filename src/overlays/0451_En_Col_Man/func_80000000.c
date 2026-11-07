// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void EnColMan_Init(Actor* thisx, PlayState* play) {
    EnColMan* this = (EnColMan*)thisx;

    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->actor.attentionRangeType = ATTENTION_RANGE_1;
    this->scale = (BREG(55) / 1000.0f) + 0.01f;

    switch (this->actor.params) {
        case EN_COL_MAN_HEART_PIECE:
        case EN_COL_MAN_RECOVERY_HEART:
        default:
            ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 10.0f);
            ref_func_80AFDD60(this);
            break;

        case EN_COL_MAN_FALLING_ROCK:
            ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 10.0f);
            ref_func_80AFDF60(this);
            break;

        case EN_COL_MAN_CUTSCENE_BOMB:
        case EN_COL_MAN_GAMEPLAY_BOMB:
            ref_func_80AFE234(this);
            break;
    }
}
