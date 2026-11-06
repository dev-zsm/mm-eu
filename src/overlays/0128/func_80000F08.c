// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_Update(Actor* thisx, PlayState* play) {
    static Vec3f sBlureP1Offset = { 0.0f, 7.0f, -6.0f };
    static Vec3f sBlureP2LeftOffset = { 12.0f, 0.0f, -5.0f };
    static Vec3f sBlureP2RightOffset = { -12.0f, 0.0f, -5.0f };
    s32 pad;
    EnBomChu* this = (EnBomChu*)thisx;
    Vec3f blureP1;
    Vec3f blureP2;
    WaterBox* waterBox;
    f32 waterY;

    if (this->actor.floorBgId != BGCHECK_SCENE) {
        EnBomChu_HandleNonSceneCollision(this, play);
    }

    if (this->shouldTimerCountDown) {
        this->timer--;
    }

    this->actionFunc(this, play);

    if ((this->actionFunc != EnBomChu_WaitForDeath) &&
        SurfaceType_IsWallDamage(&play->colCtx, this->actor.floorPoly, this->actor.floorBgId)) {
        EnBomChu_Explode(this, play);
        return;
    }

    Actor_MoveWithoutGravity(&this->actor);

    this->collider.dim.worldSphere.center.x = this->actor.world.pos.x;
    this->collider.dim.worldSphere.center.y = this->actor.world.pos.y;
    this->collider.dim.worldSphere.center.z = this->actor.world.pos.z;

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    if (this->actionFunc != EnBomChu_WaitForRelease) {
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }

    this->actor.focus.pos.x = this->actor.world.pos.x + (20.0f * this->axisUp.x);
    this->actor.focus.pos.y = this->actor.world.pos.y + (20.0f * this->axisUp.y);
    this->actor.focus.pos.z = this->actor.world.pos.z + (20.0f * this->axisUp.z);

    if (this->isMoving) {
        this->visualJitter =
            (5.0f + (Rand_ZeroOne() * 3.0f)) * Math_SinS(((s32)(Rand_ZeroOne() * 0x200) + 0x3000) * this->timer);
        EnBomChu_ActorCoordsToWorld(this, &sBlureP1Offset, &blureP1);

        EnBomChu_ActorCoordsToWorld(this, &sBlureP2LeftOffset, &blureP2);
        EffectBlure_AddVertex(Effect_GetByIndex(this->blure1Index), &blureP1, &blureP2);

        EnBomChu_ActorCoordsToWorld(this, &sBlureP2RightOffset, &blureP2);
        EffectBlure_AddVertex(Effect_GetByIndex(this->blure2Index), &blureP1, &blureP2);

        waterY = this->actor.world.pos.y;

        if (BgCheck_GetWaterSurfaceNoBgIdAlt(play, &play->colCtx, this->actor.world.pos.x, this->actor.world.pos.z,
                                             &waterY, &waterBox)) {
            this->actor.depthInWater = waterY - this->actor.world.pos.y;

            if (this->actor.depthInWater < 0.0f) {
                if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER) {
                    EnBomChu_SpawnRipplesAndSplashes(this, play, waterY, true);
                }

                this->actor.bgCheckFlags &= ~BGCHECKFLAG_WATER;
                return;
            }

            if (!(this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (this->timer != 120)) {
                EnBomChu_SpawnRipplesAndSplashes(this, play, waterY, true);
            } else {
                EffectSsBubble_Spawn(play, &this->actor.world.pos, 0.0f, 3.0f, 15.0f, 0.25f);
            }

            this->actor.bgCheckFlags |= BGCHECKFLAG_WATER;
        } else {
            this->actor.bgCheckFlags &= ~BGCHECKFLAG_WATER;
            this->actor.depthInWater = BGCHECK_Y_MIN;
        }
    }
}
