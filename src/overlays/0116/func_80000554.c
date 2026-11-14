// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000554(EnHorseLinkChild* this, PlayState* play) {
    f32 distToPlayer = Actor_WorldDistXZToActor(&this->actor, &GET_PLAYER(play)->actor);
    s32 animIndex;

    if (SkelAnime_Update(&this->skin.skelAnime)) {
        if ((distToPlayer < 1000.0f) && (distToPlayer > 70.0f)) {
            EnHorseLinkChild_SetupGreetPlayer(this);
            return;
        }

        if (this->animIndex == OOT_CHILD_EPONA_ANIM_WHINNY) {
            animIndex = OOT_CHILD_EPONA_ANIM_IDLE;
        } else {
            animIndex = OOT_CHILD_EPONA_ANIM_WHINNY;
        }

        if (this->animIndex != animIndex) {
            this->animIndex = animIndex;
            Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this),
                             0.0f, Animation_GetLastFrame(sAnimations[this->animIndex]), ANIMMODE_ONCE, -5.0f);
        } else {
            Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this),
                             0.0f, Animation_GetLastFrame(sAnimations[this->animIndex]), ANIMMODE_ONCE, 0.0f);
        }
    }
}
