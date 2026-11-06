// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void ref_func_808A2918(EnBoom* this, PlayState* play) {
    Actor* targetActor;
    Player* player = GET_PLAYER(play);
    s32 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    s16 sp6C;
    Actor* temp;
    f32 sp64;
    f32 distXYZ;

    targetActor = this->moveTo;

    if (targetActor != NULL) {
        sp72 = Actor_WorldYawTowardPoint(&this->actor, &targetActor->focus.pos);
        sp70 = this->actor.world.rot.y - sp72;
        sp6E = Actor_WorldPitchTowardPoint(&this->actor, &targetActor->focus.pos);
        sp6C = this->actor.world.rot.x - sp6E;

        sp64 = (200.0f - Math_Vec3f_DistXYZ(&this->actor.world.pos, &targetActor->focus.pos)) * 0.005f;
        if (sp64 < 0.12f) {
            sp64 = 0.12f;
        }

        if ((&player->actor != targetActor) &&
            ((targetActor->update == NULL) || ((this->unk_1CF < 0) && (ABS_ALT(sp70) > 0x4000)))) {
            this->moveTo = NULL;
        } else {
            if (this->unk_1CE != 0) {
                this->unk_1CE--;
                this->actor.world.rot.y += (this->actor.params == ZORA_BOOMERANG_LEFT) ? 0x190 : -0x190;
            } else {
                if (this->unk_1CF > 0) {
                    this->unk_1CF--;
                } else {
                    this->unk_1CF = -1;
                }

                Math_ScaledStepToS(&this->actor.world.rot.y, sp72,
                                   (this->unk_1CF > 0) ? 0x3E8 : TRUNCF_BINANG(ABS_ALT(sp70) * sp64));
            }

            Math_ScaledStepToS(&this->actor.world.rot.x, sp6E, ABS_ALT(sp6C) * sp64);
        }
    }

    Actor_SetSpeeds(&this->actor, 12.0f);
    Actor_MoveWithGravity(&this->actor);
    ref_func_808A24DC(this, play);
    Actor_PlaySfx_Flagged(&this->actor, NA_SE_IT_BOOMERANG_FLY - SFX_FLAG);

    if ((this->collider.base.atFlags & AT_HIT) && (((this->collider.base.at->id == ACTOR_EN_ITEM00) &&
                                                    (this->collider.base.at->params != ITEM00_HEART_CONTAINER) &&
                                                    (this->collider.base.at->params != ITEM00_HEART_PIECE)) ||
                                                   (this->collider.base.at->id == ACTOR_EN_SI))) {
        this->unk_1C8 = this->collider.base.at;
        if (this->collider.base.at->id == ACTOR_EN_SI) {
            this->collider.base.at->flags |= ACTOR_FLAG_HOOKSHOT_ATTACHED;
        }
    }

    if (DECR(this->unk_1CC) != 0) {
        s32 bgId;
        Vec3f sp50;
        s32 pad;

        sp74 = BgCheck_EntityLineTest1(&play->colCtx, &this->actor.prevPos, &this->actor.world.pos, &sp50,
                                       &this->actor.wallPoly, true, true, true, true, &bgId);
        if (sp74) {
            if (ref_func_800B90AC(play, &this->actor, this->actor.wallPoly, bgId, &sp50)) {
                sp74 = false;
            } else {
                CollisionCheck_SpawnShieldParticlesMetal(play, &sp50);
            }
        }

        if (sp74) {
            this->actor.world.rot.x = -this->actor.world.rot.x;
            this->actor.world.rot.y += 0x8000;
            this->moveTo = &player->actor;
            this->unk_1CC = 0;
        }
    }

    if (this->unk_1CC <= 16) {
        distXYZ = Math_Vec3f_DistXYZ(&this->actor.world.pos, &player->actor.focus.pos);

        if (&player->actor != this->moveTo) {
            if (this->moveTo == 0) {
                this->unk_1CE = 8;
            }
            this->moveTo = &player->actor;
        }

        if (distXYZ < 40.0f) {
            targetActor = this->unk_1C8;
            if (targetActor != NULL) {
                Math_Vec3f_Copy(&targetActor->world.pos, &player->actor.world.pos);
                if (targetActor->id == ACTOR_EN_ITEM00) {
                    targetActor->gravity = -0.9f;
                    targetActor->bgCheckFlags &= ~(BGCHECKFLAG_GROUND | BGCHECKFLAG_GROUND_TOUCH);
                } else {
                    targetActor->flags &= ~ACTOR_FLAG_HOOKSHOT_ATTACHED;
                }
            }
            Actor_Kill(&this->actor);
        }
    }

    targetActor = this->unk_1C8;
    if (targetActor != NULL) {
        if (targetActor->update == NULL) {
            this->unk_1C8 = NULL;
        } else {
            Math_Vec3f_Copy(&targetActor->world.pos, &this->actor.world.pos);
        }
    }
}
