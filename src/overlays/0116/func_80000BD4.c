// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000BD4(EnHorseLinkChild* this, PlayState* play) {
    Player* player;
    f32 distToPlayer;
    s32 isAnimFinished;
    s32 animIndex;

    ref_func_808DF088(this, play);

    player = GET_PLAYER(play);
    distToPlayer = Actor_WorldDistXZToActor(&this->actor, &player->actor);
    animIndex = this->animIndex;
    isAnimFinished = SkelAnime_Update(&this->skin.skelAnime);

    if (isAnimFinished || (this->animIndex == OOT_CHILD_EPONA_ANIM_WHINNY) ||
        (this->animIndex == OOT_CHILD_EPONA_ANIM_IDLE)) {
        
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_ENTERED_ZORA_HALL)) {
            f32 distToHome = Math3D_Vec3f_DistXYZ(&this->actor.world.pos, &this->actor.home.pos);
            s32 pad;

            if (Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &this->actor.home.pos) > 250.0f) {
                if (distToHome >= 300.0f) {
                    animIndex = OOT_CHILD_EPONA_ANIM_GALLOP;
                    this->actor.speed = 6.0f;
                } else if ((distToHome < 300.0f) && (distToHome >= 150.0f)) {
                    animIndex = OOT_CHILD_EPONA_ANIM_TROT;
                    this->actor.speed = 4.0f;
                } else if ((distToHome < 150.0f) && (distToHome >= 70.0f)) {
                    animIndex = OOT_CHILD_EPONA_ANIM_WALK;
                    this->footstepCounter = 0;
                    this->actor.speed = 2.0f;
                } else {
                    this->actor.speed = 0.0f;
                    if (this->animIndex == OOT_CHILD_EPONA_ANIM_IDLE) {
                        animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_WHINNY : OOT_CHILD_EPONA_ANIM_IDLE;
                    } else {
                        animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_IDLE : OOT_CHILD_EPONA_ANIM_WHINNY;
                    }
                }
            } else if (distToPlayer < 200.0f) {
                animIndex = OOT_CHILD_EPONA_ANIM_GALLOP;
                this->actor.speed = 6.0f;
            } else if (distToPlayer < 300.0f) {
                animIndex = OOT_CHILD_EPONA_ANIM_TROT;
                this->actor.speed = 4.0f;
            } else if (distToPlayer < 400.0f) {
                animIndex = OOT_CHILD_EPONA_ANIM_WALK;
                this->footstepCounter = 0;
                this->actor.speed = 2.0f;
            } else {
                this->actor.speed = 0.0f;
                if (this->animIndex == OOT_CHILD_EPONA_ANIM_IDLE) {
                    animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_WHINNY : OOT_CHILD_EPONA_ANIM_IDLE;
                } else {
                    animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_IDLE : OOT_CHILD_EPONA_ANIM_WHINNY;
                }
            }
        } else {
            this->actor.speed = 0.0f;
            if (this->animIndex == OOT_CHILD_EPONA_ANIM_IDLE) {
                animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_WHINNY : OOT_CHILD_EPONA_ANIM_IDLE;
            } else {
                animIndex = (isAnimFinished == true) ? OOT_CHILD_EPONA_ANIM_IDLE : OOT_CHILD_EPONA_ANIM_WHINNY;
            }
        }
    }

    if ((this->animIndex != animIndex) || (isAnimFinished == true)) {
        this->animIndex = animIndex;
        Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this), 0.0f,
                         Animation_GetLastFrame(sAnimations[this->animIndex]), ANIMMODE_ONCE, -5.0f);
    } else {
        Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this),
                         this->skin.skelAnime.curFrame, Animation_GetLastFrame(sAnimations[this->animIndex]),
                         ANIMMODE_ONCE, 0.0f);
    }
}
