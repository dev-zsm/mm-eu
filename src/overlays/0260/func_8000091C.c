// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_Fall(ObjGrassCarry* this, PlayState* play) {
    s16 angle;
    s32 atHit = (this->collider.base.atFlags & AT_HIT) != 0;
    Vec3f pos;
    s32 i;

    if (atHit) {
        this->collider.base.atFlags &= ~AT_HIT;
    }

    this->fallTimer--;

    if ((this->actor.bgCheckFlags & (BGCHECKFLAG_GROUND | BGCHECKFLAG_GROUND_TOUCH | BGCHECKFLAG_WALL)) || atHit ||
        (this->fallTimer <= 0)) {
        ObjGrassCarry_SpawnFragments(&this->actor.world.pos, play);
        ObjGrassCarry_DropCollectible(&this->actor.world.pos, this->dropTable, play);

        this->actor.draw = NULL;
        this->actor.shape.shadowDraw = NULL;

        if (this->grassManager != NULL) {
            this->actor.room = this->grassManager->actor.room;
        }

        if (!(this->actor.bgCheckFlags & BGCHECKFLAG_WATER)) {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_PLANT_BROKEN);
        }
        ObjGrassCarry_SetupIdle(this);
        return;
    }

    if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
        pos.y = this->actor.world.pos.y + this->actor.depthInWater;

        for (angle = 0, i = 0; i < 4; i++, angle += 0x4000) {
            pos.x = this->actor.world.pos.x + (Math_SinS((s32)(Rand_ZeroOne() * 7200.0f) + angle) * 15.0f);
            pos.z = this->actor.world.pos.z + (Math_CosS((s32)(Rand_ZeroOne() * 7200.0f) + angle) * 15.0f);
            EffectSsGSplash_Spawn(play, &pos, NULL, NULL, 0, 190);
        }

        pos.x = this->actor.world.pos.x;
        pos.z = this->actor.world.pos.z;

        EffectSsGSplash_Spawn(play, &pos, NULL, NULL, 0, 280);
        EffectSsGRipple_Spawn(play, &pos, 300, 700, 0);

        this->actor.terminalVelocity = -3.0f;
        this->actor.velocity.x *= 0.1f;
        this->actor.velocity.y *= 0.4f;
        this->actor.velocity.z *= 0.1f;
        this->actor.gravity *= 0.5f;

        sRotSpeedX >>= 1;
        sRotSpeedXTarget >>= 1;
        sRotSpeedY >>= 1;
        sRotSpeedYTarget >>= 1;
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_WATER_TOUCH;
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
    }

    Math_StepToS(&sRotSpeedX, sRotSpeedXTarget, 0x1F4);
    Math_StepToS(&sRotSpeedY, sRotSpeedYTarget, 0xAA);
    this->actor.shape.rot.x += sRotSpeedX;
    this->actor.shape.rot.y += sRotSpeedY;
    ObjGrassCarry_UpdatePos(this);
    ObjGrassCarry_UpdateBgCheckInfo(this, play);

    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
