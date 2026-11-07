// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void ref_func_808AEAE0(EnBombf* this, PlayState* play) {
    s32 pad;
    s32 pad2;
    EnBombf* bombf;
    Player* player = GET_PLAYER(play);
    s32 pad3;

    if (this->unk_204 >= 1.0f) {
        if (Actor_HasParent(&this->actor, play)) {
            bombf = (EnBombf*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOMBF, this->actor.world.pos.x,
                                          this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, ENBOMBF_0);
            if (bombf != NULL) {
                ref_func_800B8C20(&this->actor, &bombf->actor, play);
                this->timer = 180;
                this->unk_204 = 0.0f;
                Actor_PlaySfx(&this->actor, NA_SE_PL_PULL_UP_ROCK);
                this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
            } else {
                player->actor.child = NULL;
                player->heldActor = NULL;
                player->interactRangeActor = NULL;
                this->actor.parent = NULL;
                player->stateFlags1 &= ~PLAYER_STATE1_CARRYING_ACTOR;
            }
        } else if ((this->colliderCylinder.base.acFlags & AC_HIT) &&
                   ((this->colliderCylinder.elem.acHitElem->atDmgInfo.dmgFlags & 0x13828) ||
                    ((this->colliderCylinder.elem.acHitElem->atDmgInfo.dmgFlags & 0x200) &&
                     (player->transformation == PLAYER_FORM_GORON) && (player->actor.speed > 15.0f)))) {
            this->colliderCylinder.base.acFlags &= ~AC_HIT;
            if (this->colliderCylinder.base.ac->category != ACTORCAT_BOSS) {
                bombf = (EnBombf*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOMBF, this->actor.world.pos.x,
                                              this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, ENBOMBF_0);
                if (bombf != NULL) {
                    bombf->unk_1F8 = 1;
                    bombf->timer = 0;
                    this->timer = 180;
                    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
                    this->unk_204 = 0.0f;
                }
            }
        } else {
            if (Player_IsBurningStickInRange(play, &this->actor.world.pos, 30.0f, 50.0f)) {
                bombf = (EnBombf*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOMBF, this->actor.world.pos.x,
                                              this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, ENBOMBF_0);
                if (bombf != NULL) {
                    bombf->timer = 100;
                    this->timer = 180;
                    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
                    this->unk_204 = 0.0f;
                }
            } else {
                if (!Actor_HasParent(&this->actor, play)) {
                    Actor_OfferCarry(&this->actor, play);
                    return;
                }
                player->actor.child = NULL;
                player->heldActor = NULL;
                player->interactRangeActor = NULL;
                this->actor.parent = NULL;
                player->stateFlags1 &= ~PLAYER_STATE1_CARRYING_ACTOR;
                this->actor.world.pos = this->actor.home.pos;
            }
        }
    } else {
        if (this->timer == 0) {
            this->unk_204 += 0.05f;
            if (this->unk_204 >= 1.0f) {
                this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
            }
        }

        if (Actor_HasParent(&this->actor, play)) {
            player->actor.child = NULL;
            player->heldActor = NULL;
            player->interactRangeActor = NULL;
            this->actor.parent = NULL;
            player->stateFlags1 &= ~PLAYER_STATE1_CARRYING_ACTOR;
            this->actor.world.pos = this->actor.home.pos;
        }
    }
}
