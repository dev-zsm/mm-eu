// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_Update(Actor* thisx, PlayState* play) {
    Vec3f effVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f bomb2Accel = { 0.0f, 0.1f, 0.0f }; 
    Vec3f effAccel = { 0.0f, 0.0f, 0.0f };
    Vec3f effPos;
    Vec3f dustAccel = { 0.0f, 0.6f, 0.0f };
    Color_RGBA8 dustColor = { 255, 255, 255, 255 };
    EnBom* this = (EnBom*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(play);

    if (player->stateFlags1 & PLAYER_STATE1_2) {
        return;
    }

    if (Player_GetMask(play) == PLAYER_MASK_GIANT) {
        Actor_Kill(thisx);
        return;
    }

    if (this->unk_1FC != 0) {
        this->unk_1FC--;
        Math_ApproachZeroF(&thisx->speed, 1.0f, 1.0f);
        Actor_MoveWithGravity(thisx);
        Actor_UpdateBgCheckInfo(play, thisx, 35.0f, 10.0f, 36.0f, UPDBGCHECKINFO_FLAG_4);
        if (this->unk_1FC == 0) {
            if (this->isPowderKeg) {
                gSaveContext.powderKegTimer = 0;
            }
            Actor_Kill(thisx);
        }
    } else {
        thisx->gravity = -1.2f;
        if (this->timer != 0) {
            if (!this->isPowderKeg || (EnBom_Explode == this->actionFunc) || !Play_InCsMode(play)) {
                this->timer--;
            }
        }

        if ((!this->isPowderKeg && (this->timer == 67)) || (this->isPowderKeg && (this->timer <= 2400))) {
            Actor_PlaySfx(thisx, NA_SE_PL_TAKE_OUT_SHIELD);
            Actor_SetScale(thisx, enBomScales[this->isPowderKeg]);
        }

        if ((thisx->xzDistToPlayer >= 20.0f) || (fabsf(thisx->playerHeightRel) >= 80.0f)) {
            this->unk_1F8 = 1;
        }

        this->actionFunc(this, play);

        Actor_UpdateBgCheckInfo(play, thisx, 35.0f, 10.0f, 36.0f,
                                UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_4 |
                                    UPDBGCHECKINFO_FLAG_8 | UPDBGCHECKINFO_FLAG_10);
        if (thisx->params == BOMB_TYPE_BODY) {
            static Vec3us ref_D_80872ED4[] = {
                { 40, 20, 100 },
                { 300, 60, 600 },
            };
            Vec3us* sp60 = &ref_D_80872ED4[this->isPowderKeg];

            
            dustAccel.y = 0.2f;
            Math_Vec3f_Copy(&effPos, &thisx->home.pos);
            if ((play->gameplayFrames % 2) == 0) {
                EffectSsGSpk_SpawnFuse(play, thisx, &effPos, &effVelocity, &effAccel);
            }
            if (this->isPowderKeg) {
                Audio_PlaySfx_AtPosWithChannelIO(&thisx->projectedPos, NA_SE_IT_BIG_BOMB_IGNIT - SFX_FLAG,
                                                 (this->flashSpeedScale == 7)   ? 0
                                                 : (this->flashSpeedScale == 3) ? 1
                                                                                : 2);
            } else {
                Actor_PlaySfx(thisx, NA_SE_IT_BOMB_IGNIT - SFX_FLAG);
            }

            effPos.y += 3.0f;
            ref_func_800B0DE0(play, &effPos, &effVelocity, &dustAccel, &dustColor, &dustColor, 50, 5);

            if ((this->collider1.base.acFlags & AC_HIT) ||
                ((this->collider1.base.ocFlags1 & OC1_HIT) && ((this->collider1.base.oc->category == ACTORCAT_ENEMY) ||
                                                               (this->collider1.base.oc->category == ACTORCAT_BOSS)))) {
                this->timer = 0;
                thisx->shape.rot.z = 0;
            } else {
                
                
                if ((this->timer > 100) && Player_IsBurningStickInRange(play, &thisx->world.pos, 30.0f, 50.0f)) {
                    this->timer = 100;
                }
            }

            dustAccel.y = 0.2f;
            effPos = thisx->world.pos;
            effPos.y += 10.0f;

            
            if ((this->timer == sp60->x) || (this->timer == sp60->y) || (this->timer == 3)) {
                thisx->shape.rot.z = 0;
                this->flashSpeedScale >>= 1;
            }

            if ((this->timer < sp60->z) && (this->timer & (this->flashSpeedScale + 1))) {
                Math_ApproachF(&this->unk_1F4, 140.0f, 1.0f, 140.0f / this->flashSpeedScale);
            } else {
                Math_ApproachZeroF(&this->unk_1F4, 1.0f, 140.0f / this->flashSpeedScale);
            }

            if (this->timer < 3) {
                Actor_SetScale(thisx, thisx->scale.x + 0.002f);
            }

            if (this->timer == 0) {
                effPos = thisx->world.pos;
                effPos.y += 10.0f;
                if (Actor_HasParent(thisx, play)) {
                    effPos.y += 30.0f;
                }
                
                
                Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, effPos.x, effPos.y - 10.0f, effPos.z, 0, 0, 0,
                            CLEAR_TAG_PARAMS(this->isPowderKeg));
                Actor_RequestQuakeAndRumble(thisx, play, sQuakeY[this->isPowderKeg],
                                            sQuakeDurations[this->isPowderKeg]);
                play->envCtx.adjLightSettings.light1Color[0] = play->envCtx.adjLightSettings.light1Color[1] =
                    play->envCtx.adjLightSettings.light1Color[2] = 250;
                play->envCtx.adjLightSettings.ambientColor[0] = play->envCtx.adjLightSettings.ambientColor[1] =
                    play->envCtx.adjLightSettings.ambientColor[2] = 250;
                Camera_AddQuake(&play->mainCamera, 2, 11, 8);
                thisx->params = BOMB_TYPE_EXPLOSION;
                this->timer = 10;
                thisx->flags |= (ACTOR_FLAG_DRAW_CULLING_DISABLED | ACTOR_FLAG_FREEZE_EXCEPTION);
                this->actionFunc = EnBom_Explode;
                if (this->isPowderKeg) {
                    gSaveContext.powderKegTimer = 0;
                    Actor_PlaySfx(thisx, NA_SE_IT_BIG_BOMB_EXPLOSION);
                } else {
                    Actor_PlaySfx(thisx, NA_SE_IT_BOMB_EXPLOSION);
                }
            }
        }

        Actor_SetFocus(thisx, 20.0f);

        if (thisx->params <= BOMB_TYPE_BODY) {
            Collider_UpdateCylinder(thisx, &this->collider1);

            
            if (!Actor_HasParent(thisx, play) && (this->unk_1F8 != 0)) {
                CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider1.base);
            }
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider1.base);
        }

        if ((enBomScales[this->isPowderKeg] <= thisx->scale.x) && (thisx->params != BOMB_TYPE_EXPLOSION)) {
            if (thisx->depthInWater >= 20.0f) {
                Vec3f effPos;

                effPos.x = thisx->world.pos.x;
                effPos.y = thisx->world.pos.y + thisx->depthInWater;
                effPos.z = thisx->world.pos.z;
                EffectSsGRipple_Spawn(play, &effPos, 70, 500, 0);
                EffectSsGRipple_Spawn(play, &effPos, 70, 500, 10);
                effPos.y += 10.0f;
                EffectSsGSplash_Spawn(play, &effPos, NULL, NULL, 1, 500);
                Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, effPos.x, effPos.y, effPos.z, 0, 0, 1,
                            CLEAR_TAG_PARAMS(CLEAR_TAG_SMOKE));
                SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 30, NA_SE_IT_BOMB_UNEXPLOSION);
                this->unk_1F4 = 0.0f;
                thisx->velocity.y = (KREG(83) * 0.1f) + -2.0f;
                thisx->gravity = (KREG(84) * 0.1f) + -0.5f;
                this->unk_1FC = KREG(81) + 10;
            } else if (thisx->bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
                thisx->bgCheckFlags &= ~BGCHECKFLAG_WATER_TOUCH;
                Actor_PlaySfx(thisx, NA_SE_EV_BOMB_DROP_WATER);
            }
        }
    }
}
