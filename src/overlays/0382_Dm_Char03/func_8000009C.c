// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void DmChar03_Init(Actor* thisx, PlayState* play) {
    DmChar03* this = (DmChar03*)thisx;

    this->animIndex = DMCHAR03_ANIM_FALL_OVER;
    this->actor.lockOnArrowOffset = 3000.0f;
    this->unk_18E = false;
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gDekuMaskSkel, NULL, NULL, NULL, 0);
    DmChar03_ChangeAnim(&this->skelAnime, &sAnimationInfo[DMCHAR03_ANIM_FALL_OVER], 0);
    Actor_SetScale(&this->actor, 0.01f);
    this->actionFunc = DmChar03_DoNothing;
}
