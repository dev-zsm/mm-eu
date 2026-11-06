// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arms_hook.h"

void ArmsHook_Shoot(ArmsHook* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if ((this->actor.parent == NULL) || !Player_IsHoldingHookshot(player)) {
        ArmsHook_DetachFromActor(this);
        Actor_Kill(&this->actor);
        return;
    }

    Actor_PlaySfx_Flagged2(&player->actor, NA_SE_IT_HOOKSHOT_CHAIN - SFX_FLAG);
    ArmsHook_CheckForCancel(this);

    if ((this->timer != 0) && (this->collider.base.atFlags & AT_HIT) &&
        (this->collider.elem.atHitElem->elemMaterial != ELEM_MATERIAL_UNK4)) {
        Actor* touchedActor = this->collider.base.at;

        if ((touchedActor->update != NULL) &&
            (touchedActor->flags & (ACTOR_FLAG_HOOKSHOT_PULLS_ACTOR | ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER))) {
            if (this->collider.elem.atHitElem->acElemFlags & ACELEM_HOOKABLE) {
                ArmsHook_AttachToActor(this, touchedActor);
                if (CHECK_FLAG_ALL(touchedActor->flags, ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER)) {
                    ArmsHook_PullPlayer(this);
                }
            }
        }
        this->timer = 0;
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_IT_HOOKSHOT_STICK_CRE);

        return;
    }

    if (DECR(this->timer) == 0) {
        Actor* attachedActor = this->attachedActor;
        Vec3f bodyDistDiffVec;
        Vec3f newPos;
        f32 bodyDistDiff;
        f32 phi_f16;
        s32 pad;

        if (attachedActor != NULL) {
            if ((attachedActor->update == NULL) ||
                !CHECK_FLAG_ALL(attachedActor->flags, ACTOR_FLAG_HOOKSHOT_ATTACHED)) {
                attachedActor = NULL;
                this->attachedActor = NULL;
            } else if (this->actor.child != NULL) {
                f32 curActorOffsetXYZ = Actor_WorldDistXYZToActor(&this->actor, attachedActor);
                f32 attachPointOffsetXYZ = sqrtf(SQXYZ(this->attachPointOffset));

                
                Math_Vec3f_Diff(&attachedActor->world.pos, &this->attachPointOffset, &this->actor.world.pos);

                
                
                
                if ((curActorOffsetXYZ - attachPointOffsetXYZ) > 50.0f) {
                    ArmsHook_DetachFromActor(this);
                    attachedActor = NULL;
                }
            }
        }

        {
            f32 velocity;

            bodyDistDiff =
                Math_Vec3f_DistXYZAndStoreDiff(&player->rightHandWorld.pos, &this->actor.world.pos, &bodyDistDiffVec);

            if (bodyDistDiff < 30.0f) {
                velocity = 0.0f;
                phi_f16 = 0.0f;
            } else {
                if (this->actor.child != NULL) {
                    velocity = 30.0f;
                } else if (attachedActor != NULL) {
                    velocity = 50.0f;
                } else {
                    velocity = 200.0f;
                }
                phi_f16 = bodyDistDiff - velocity;
                if (bodyDistDiff <= velocity) {
                    phi_f16 = 0.0f;
                }
                velocity = phi_f16 / bodyDistDiff;
            }

            newPos.x = bodyDistDiffVec.x * velocity;
            newPos.y = bodyDistDiffVec.y * velocity;
            newPos.z = bodyDistDiffVec.z * velocity;
        }

        if (this->actor.child == NULL) {
            
            Math_Vec3f_Sum(&player->rightHandWorld.pos, &newPos, &this->actor.world.pos);
            if (attachedActor != NULL) {
                Math_Vec3f_Sum(&this->actor.world.pos, &this->attachPointOffset, &attachedActor->world.pos);
            }
        } else {
            
            Math_Vec3f_Diff(&bodyDistDiffVec, &newPos, &player->actor.velocity);
            player->actor.world.rot.x = Math_Atan2S_XY(sqrtf(SQXZ(bodyDistDiffVec)), -bodyDistDiffVec.y);
        }

        if (phi_f16 < 50.0f) {
            ArmsHook_DetachFromActor(this);
            if (phi_f16 == 0.0f) {
                ArmsHook_SetupAction(this, ArmsHook_Wait);
                if (ArmsHook_AttachToPlayer(this, player)) {
                    Math_Vec3f_Diff(&this->actor.world.pos, &player->actor.world.pos, &player->actor.velocity);
                    player->actor.velocity.y -= 20.0f;
                }
            }
        }
    } else {
        CollisionPoly* poly;
        s32 bgId;
        Vec3f posResult;
        Vec3f prevFrameDiff;
        Vec3f sp60;

        Actor_MoveWithGravity(&this->actor);
        Math_Vec3f_Diff(&this->actor.world.pos, &this->actor.prevPos, &prevFrameDiff);
        Math_Vec3f_Sum(&this->unk1E0, &prevFrameDiff, &this->unk1E0);
        this->actor.shape.rot.x = Math_Atan2S_XY(this->actor.speed, -this->actor.velocity.y);
        sp60.x = this->unk1EC.x - (this->unk1E0.x - this->unk1EC.x);
        sp60.y = this->unk1EC.y - (this->unk1E0.y - this->unk1EC.y);
        sp60.z = this->unk1EC.z - (this->unk1E0.z - this->unk1EC.z);
        if (BgCheck_EntityLineTest1(&play->colCtx, &sp60, &this->unk1E0, &posResult, &poly, true, true, true, true,
                                    &bgId) &&
            (!ref_func_800B90AC(play, &this->actor, poly, bgId, &posResult) ||
             BgCheck_ProjectileLineTest(&play->colCtx, &sp60, &this->unk1E0, &posResult, &poly, true, true, true, true,
                                        &bgId))) {
            f32 nx = COLPOLY_GET_NORMAL(poly->normal.x);
            f32 nz = COLPOLY_GET_NORMAL(poly->normal.z);

            Math_Vec3f_Copy(&this->actor.world.pos, &posResult);
            this->actor.world.pos.x += 10.0f * nx;
            this->actor.world.pos.z += 10.0f * nz;
            this->timer = 1;
            if (SurfaceType_IsHookshotSurface(&play->colCtx, poly, bgId)) {
                DynaPolyActor* dynaPolyActor;

                if (bgId != BGCHECK_SCENE) {
                    dynaPolyActor = DynaPoly_GetActor(&play->colCtx, bgId);
                    if (dynaPolyActor != NULL) {
                        ArmsHook_AttachToActor(this, &dynaPolyActor->actor);
                    }
                }
                ArmsHook_PullPlayer(this);
                Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_IT_HOOKSHOT_STICK_OBJ);
            } else {
                CollisionCheck_SpawnShieldParticlesMetal(play, &this->actor.world.pos);
                Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_IT_HOOKSHOT_REFLECT);
            }
        } else if (CHECK_BTN_ANY(CONTROLLER1(&play->state)->press.button,
                                 BTN_A | BTN_B | BTN_R | BTN_CUP | BTN_CLEFT | BTN_CRIGHT | BTN_CDOWN)) {
            s32 pad;

            this->timer = 1;
        }
    }
}
