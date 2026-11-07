// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AAC63C(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_Init(play, &this->skelAnime, &object_dmask_Skel_010B0, NULL, NULL, NULL, 0);
    if (DMCHAR05_GET(&this->actor) == DMCHAR05_0) {
        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[DMCHAR05_ANIM_0], 0);
    } else {
        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[DMCHAR05_ANIM_1], 0);
    }
    this->actionFunc = ref_func_80AACC48;
}
