// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void EnBombf_Init(Actor* thisx, PlayState* play2) {
    f32 yOffset = 0.0f;
    PlayState* play = play2;
    EnBombf* this = (EnBombf*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->unk_1F8 = 1;

    Collider_InitCylinder(play, &this->colliderCylinder);
    Collider_InitJntSph(play, &this->colliderJntSph);
    Collider_SetCylinder(play, &this->colliderCylinder, thisx, &sCylinderInit);
    Collider_SetJntSph(play, &this->colliderJntSph, thisx, &sJntSphInit, this->colliderJntSphElements);

    if (ENBOMBF_GET(thisx) == ENBOMBF_0) {
        yOffset = 1000.0f;
    }

    ActorShape_Init(&thisx->shape, yOffset, ActorShadow_DrawCircle, 12.0f);

    thisx->focus.pos = thisx->world.pos;
    thisx->colChkInfo.cylRadius = 10;
    thisx->colChkInfo.cylHeight = 10;
    thisx->attentionRangeType = ATTENTION_RANGE_0;

    if (ENBOMBF_GET(thisx) == ENBOMBF_0) {
        this->timer = 140;
        this->unk_1FE = 15;
        thisx->gravity = -1.5f;
        Actor_ChangeCategory(play, &play->actorCtx, thisx, ACTORCAT_EXPLOSIVES);
        thisx->colChkInfo.mass = 200;
        thisx->flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
        EnBombf_SetupAction(this, ref_func_808AEE3C);
    } else {
        thisx->colChkInfo.mass = MASS_IMMOVABLE;
        this->unk_1FC = 1;
        this->unk_204 = 1.0f;
        ref_func_808AEAB8(this, ENBOMBF_GET(thisx));
    }

    thisx->cullingVolumeScale += 31000.0f;
    thisx->cullingVolumeDistance += 31000.0f;
}
