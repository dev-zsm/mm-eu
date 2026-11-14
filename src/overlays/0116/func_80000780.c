// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000780(EnHorseLinkChild* this, PlayState* play) {
    f32 distToPlayer;
    s16 yawTowardPlayerDiff;
    s32 animIndex;

    if ((this->animIndex == OOT_CHILD_EPONA_ANIM_GALLOP) || (this->animIndex == OOT_CHILD_EPONA_ANIM_TROT) ||
        (this->animIndex == OOT_CHILD_EPONA_ANIM_WALK)) {
        yawTowardPlayerDiff =
            Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(play)->actor) - this->actor.world.rot.y;
        if (yawTowardPlayerDiff > 0x12C) {
            this->actor.world.rot.y += 0x12C;
        } else if (yawTowardPlayerDiff < -0x12C) {
            this->actor.world.rot.y -= 0x12C;
        } else {
            this->actor.world.rot.y += yawTowardPlayerDiff;
        }
        this->actor.shape.rot.y = this->actor.world.rot.y;
    }

    if (SkelAnime_Update(&this->skin.skelAnime)) {
        distToPlayer = Actor_WorldDistXZToActor(&this->actor, &GET_PLAYER(play)->actor);
        if (distToPlayer > 1000.0f) {
            EnHorseLinkChild_SetupWaitForPlayer(this, 0);
            return;
        }

        if ((distToPlayer < 1000.0f) && (distToPlayer >= 300.0f)) {
            animIndex = OOT_CHILD_EPONA_ANIM_GALLOP;
            this->actor.speed = 6.0f;
        } else if ((distToPlayer < 300.0f) && (distToPlayer >= 150.0f)) {
            animIndex = OOT_CHILD_EPONA_ANIM_TROT;
            this->actor.speed = 4.0f;
        } else if ((distToPlayer < 150.0f) && (distToPlayer >= 70.0f)) {
            animIndex = OOT_CHILD_EPONA_ANIM_WALK;
            this->footstepCounter = 0;
            this->actor.speed = 2.0f;
        } else {
            EnHorseLinkChild_SetupWaitForPlayer(this, 1);
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
