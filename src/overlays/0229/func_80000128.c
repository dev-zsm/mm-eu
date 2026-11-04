// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_nutsball.h"

void EnNutsball_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnNutsball* this = (EnNutsball*)thisx;
    Player* player = GET_PLAYER(play);
    Vec3f worldPos;
    Vec3s worldRot;
    Vec3f spawnBurstPos;
    f32 speedXZ;
    s32 bgId;
    CollisionPoly* poly;

    if (!(player->stateFlags1 &
          (PLAYER_STATE1_TALKING | PLAYER_STATE1_DEAD | PLAYER_STATE1_10000000 | PLAYER_STATE1_20000000))) {
        this->timer--;
        if (this->timer < 0) {
            this->actor.velocity.y += this->actor.gravity;
            speedXZ = sqrtf((this->actor.velocity.x * this->actor.velocity.x) +
                            (this->actor.velocity.z * this->actor.velocity.z));
            this->actor.world.rot.x = Math_Atan2S_XY(speedXZ, this->actor.velocity.y);
        }
        this->actor.home.rot.z += 0x2AA8;
        if ((this->actor.bgCheckFlags & BGCHECKFLAG_WALL) || (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) ||
            (this->actor.bgCheckFlags & BGCHECKFLAG_CEILING) || (this->collider.base.atFlags & AT_HIT) ||
            (this->collider.base.acFlags & AC_HIT) || (this->collider.base.ocFlags1 & OC1_HIT)) {
            if ((player->currentShield == PLAYER_SHIELD_HEROS_SHIELD) && (this->collider.base.atFlags & AT_HIT) &&
                (this->collider.base.atFlags & AT_TYPE_ENEMY) && (this->collider.base.atFlags & AT_BOUNCED)) {
                EnNutsball_InitColliderParams(this);
                Matrix_MtxFToYXZRot(&player->shieldMf, &worldRot, false);
                this->actor.world.rot.y = BINANG_ROT180(worldRot.y);
                this->timer = 20;
            } else {
                spawnBurstPos.x = this->actor.world.pos.x;
                spawnBurstPos.y = this->actor.world.pos.y + 4.0f;
                spawnBurstPos.z = this->actor.world.pos.z;
                EffectSsHahen_SpawnBurst(play, &spawnBurstPos, 6.0f, 0, 7, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
                if (this->actor.params == 1) {
                    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_NUTS_BROKEN);
                } else {
                    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EN_OCTAROCK_ROCK);
                }
                Actor_Kill(&this->actor);
            }
        } else {
            if (this->timer == -300) {
                Actor_Kill(&this->actor);
            }
        }

        Actor_MoveWithoutGravity(&this->actor);
        Math_Vec3f_Copy(&worldPos, &this->actor.world.pos);
        Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 5.0f, 10.0f,
                                UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_4);

        if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
            if (SurfaceType_GetWallFlags(&play->colCtx, this->actor.wallPoly, this->actor.wallBgId) &
                (WALL_FLAG_4 | WALL_FLAG_5)) {
                this->actor.bgCheckFlags &= ~BGCHECKFLAG_WALL;
                if (BgCheck_EntityLineTest1(&play->colCtx, &this->actor.prevPos, &worldPos, &this->actor.world.pos,
                                            &poly, true, false, false, true, &bgId)) {
                    if (SurfaceType_GetWallFlags(&play->colCtx, poly, bgId) & (WALL_FLAG_4 | WALL_FLAG_5)) {
                        this->actor.world.pos.x += this->actor.velocity.x * 0.01f;
                        this->actor.world.pos.z += this->actor.velocity.z * 0.01f;
                    } else {
                        this->actor.bgCheckFlags |= BGCHECKFLAG_WALL;
                    }
                } else {
                    Math_Vec3f_Copy(&this->actor.world.pos, &worldPos);
                }
            }
        }
        Collider_UpdateCylinder(&this->actor, &this->collider);

        this->actor.flags |= ACTOR_FLAG_SFX_FOR_PLAYER_BODY_HIT;

        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);

        if (this->timer < this->timerThreshold) {
            CollisionCheck_SetOC(play, &play2->colChkCtx, &this->collider.base);
        }
    }
}
