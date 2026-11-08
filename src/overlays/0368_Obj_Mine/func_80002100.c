// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_Chained(ObjMine* this, PlayState* play) {
    s32 pad; 
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    ObjMineAirChain* airChain = &this->chain.air;
    ObjMineAirLink* airLink;
    s32 i;
    f32 xAccel;
    f32 zAccel;
    f32 spin;
    s16 twistDiff;

    Math_Vec3f_Copy(&airChain->translation, &airChain->basis.y);

    
    if (ObjMine_AirWater_CheckOC(this)) {
        ObjMine_AirWater_SpawnBomb(this, play);
        ObjMine_AirWater_Noop(this);
        ObjMine_SetupExplode(this);
        return;
    }

    
    if (this->collider.base.acFlags & AC_HIT) {
        s16 torqueAngle;
        f32 torque;
        f32 torqueDiff;

        this->collider.base.acFlags &= ~AC_HIT;
        airChain->knockback = AIR_KNOCKBACK;
        ObjMine_Air_CheckAC(this, &airChain->knockbackAngle, &torqueAngle);
        torque = Math_SinS(torqueAngle) * 0x96;
        torqueDiff = -(torque / linkCount);

        for (i = 0, airLink = airChain->links; i < linkCount; i++, airLink++) {
            airLink->spin += (s16)torque;
            airLink->spin = CLAMP(airLink->spin, -0x320, 0x320);
            torque -= torqueDiff;
        }
    }

    
    if (airChain->knockback > 0.0001f) {
        xAccel = Math_SinS(airChain->knockbackAngle) * airChain->knockback;
        zAccel = Math_CosS(airChain->knockbackAngle) * airChain->knockback;
        airChain->velocity.x += xAccel;
        airChain->velocity.z += zAccel;
        Math_StepToF(&airChain->knockback, 0.0f, AIR_KNOCKBACK * 0.5f);
    }

    
    if ((Rand_Next() >> (0x20 - 5)) == 0) {
        airChain->swaySize = Rand_ZeroOne() * airChain->swayMax;
        airChain->swayPhase = Rand_Next() >> (0x20 - 16);
    }
    xAccel = Math_SinS(airChain->swayPhase) * airChain->swaySize;
    zAccel = Math_CosS(airChain->swayPhase) * airChain->swaySize;
    airChain->velocity.x += xAccel;
    airChain->velocity.z += zAccel;

    
    airChain->velocity.x += airChain->displacement.x * airChain->restore;
    airChain->velocity.z += airChain->displacement.z * airChain->restore;

    
    airChain->velocity.x *= airChain->drag;
    airChain->velocity.z *= airChain->drag;

    
    airChain->displacement.x += airChain->velocity.x;
    airChain->displacement.z += airChain->velocity.z;

    airChain->displacement.x = CLAMP(airChain->displacement.x, -5.0f, 5.0f);
    airChain->displacement.z = CLAMP(airChain->displacement.z, -5.0f, 5.0f);

    ObjMine_Air_SetBasis(this);
    ObjMine_Air_SetWorld(this);

    
    
    if (airChain->wallCheckDistSq > -1e-6f) {
        if (airChain->wallCheckDistSq <= Math3D_Dist2DSq(this->actor.world.pos.x, this->actor.world.pos.z,
                                                         this->actor.home.pos.x, this->actor.home.pos.z)) {

            Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, AIR_RADIUS, 0.0f, UPDBGCHECKINFO_FLAG_1);

            if ((this->actor.bgCheckFlags & BGCHECKFLAG_WALL) && (this->actor.wallPoly != NULL)) {
                Vec3f xzDir;
                Vec3f reflectedDir;
                Vec3f wallNormal;
                Vec3f xzVel;
                f32 xzSpeed;
                f32 invNorm; 

                xzVel.x = airChain->velocity.x;
                xzVel.y = 0.0f;
                xzVel.z = airChain->velocity.z;

                if (ObjMine_GetUnitVec3fNorm(&xzVel, &xzDir, &xzSpeed, &invNorm)) {
                    wallNormal.x = COLPOLY_GET_NORMAL(this->actor.wallPoly->normal.x);
                    wallNormal.y = COLPOLY_GET_NORMAL(this->actor.wallPoly->normal.y);
                    wallNormal.z = COLPOLY_GET_NORMAL(this->actor.wallPoly->normal.z);

                    Math3D_Vec3fReflect(&xzDir, &wallNormal, &reflectedDir);

                    xzSpeed /= 2.0f;
                    airChain->velocity.x = reflectedDir.x * xzSpeed;
                    airChain->velocity.z = reflectedDir.z * xzSpeed;
                } else {
                    airChain->velocity.x *= -0.1f;
                    airChain->velocity.z *= -0.1f;
                }
                ObjMine_Air_SetChainXZ(this);
                ObjMine_Air_SetBasis(this);
                ObjMine_Air_SetWorld(this);
            }
        }
    }

    
    
    
    
    for (i = 0, airLink = airChain->links; i < linkCount; i++, airLink++) {
        twistDiff = airLink->twist - 0x4000;
        spin = airLink->spin + (twistDiff * -0.05f) + (30.0f * Rand_ZeroOne() - 15.0f);
        spin *= 0.995f;
        airLink->spin = spin;
        airLink->twist += airLink->spin;
    }

    ref_func_800B4AEC(play, &this->actor, 0.0f);
    ObjMine_UpdateCollider(this);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
