// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000230(Actor* thisx, PlayState* play) {
    EnHorseLinkChild* this = (EnHorseLinkChild*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Actor_SetScale(&this->actor, 64.8f * 0.0001f);

    this->actor.gravity = -3.5f;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);

    this->action = OOT_CHILD_EPONA_ACTION_GREET_PLAYER;
    this->actor.speed = 0.0f;
    this->actor.focus.pos = this->actor.world.pos;
    this->actor.focus.pos.y += 70.0f;

    Skin_Init(&play->state, &this->skin, &gEponaSkel, &gEponaGallopAnim);
    this->animIndex = OOT_CHILD_EPONA_ANIM_IDLE;

    
    Animation_PlayOnce(&this->skin.skelAnime, sAnimations[OOT_CHILD_EPONA_ANIM_IDLE]);

    Collider_InitCylinder(play, &this->colldierCylinder);
    Collider_InitJntSph(play, &this->colliderJntSph);
    Collider_SetJntSph(play, &this->colliderJntSph, &this->actor, &sJntSphInit, this->colliderJntSphElements);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);

    this->footstepCounter = 0;
    this->eyeTexIndex = 0;

    if (gSaveContext.sceneLayer >= 4) { 
        EnHorseLinkChild_SetupLonLonIdle(this);
    } else {
        EnHorseLinkChild_SetupLonLonIdle(this);
    }

    this->actor.home.rot.z = this->actor.world.rot.z = this->actor.shape.rot.z = 0;
}
