// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char02.h"

void DmChar02_Init(Actor* thisx, PlayState* play) {
    DmChar02* this = (DmChar02*)thisx;

    if (gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] == ITEM_NONE) {
        this->animIndex = DMCHAR02_ANIM_HIT_GROUND;
        this->actor.lockOnArrowOffset = 3000.0f;
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
        SkelAnime_InitFlex(play, &this->skelAnime, &gClockTowerOcarinaOfTimeSkel, NULL, NULL, NULL, 0);
        DmChar02_ChangeAnim(&this->skelAnime, &sAnimationInfo[DMCHAR02_ANIM_HIT_GROUND], 0);
        Actor_SetScale(&this->actor, 0.01f);
        this->actionFunc = DmChar02_HandleCutscene;
    } else {
        Actor_Kill(&this->actor);
    }
}
