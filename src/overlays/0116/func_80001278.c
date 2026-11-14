// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80001278(EnHorseLinkChild* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 distToTargetPos;
    s32 animIndex;

    this->timer++;
    if (this->timer > 300) {
        this->isReturningHome = true;
    }

    if ((this->animIndex == OOT_CHILD_EPONA_ANIM_GALLOP) || (this->animIndex == OOT_CHILD_EPONA_ANIM_TROT) ||
        (this->animIndex == OOT_CHILD_EPONA_ANIM_WALK)) {
        if (!this->isReturningHome) {
            Horse_RotateToPoint(&this->actor, &player->actor.world.pos, 0x12C);
        } else {
            Horse_RotateToPoint(&this->actor, &this->actor.home.pos, 0x12C);
        }
    }

    if (SkelAnime_Update(&this->skin.skelAnime)) {
        if (!this->isReturningHome) {
            distToTargetPos = Actor_WorldDistXZToActor(&this->actor, &GET_PLAYER(play)->actor);
        } else {
            distToTargetPos = Math3D_Vec3f_DistXYZ(&this->actor.world.pos, &this->actor.home.pos);
        }

        if (!this->isReturningHome) {
            if (distToTargetPos >= 300.0f) {
                animIndex = OOT_CHILD_EPONA_ANIM_GALLOP;
                this->actor.speed = 6.0f;
            } else if (distToTargetPos >= 150.0f) {
                animIndex = OOT_CHILD_EPONA_ANIM_TROT;
                this->actor.speed = 4.0f;
            } else {
                animIndex = OOT_CHILD_EPONA_ANIM_WALK;
                this->footstepCounter = 0;
                this->actor.speed = 2.0f;
            }
        } else if (distToTargetPos >= 300.0f) {
            animIndex = OOT_CHILD_EPONA_ANIM_GALLOP;
            this->actor.speed = 6.0f;
        } else if (distToTargetPos >= 150.0f) {
            animIndex = OOT_CHILD_EPONA_ANIM_TROT;
            this->actor.speed = 4.0f;
        } else if (distToTargetPos >= 70.0f) {
            animIndex = OOT_CHILD_EPONA_ANIM_WALK;
            this->footstepCounter = 0;
            this->actor.speed = 2.0f;
        } else {
            EnHorseLinkChild_SetupActionFunc5(this);
            return;
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
