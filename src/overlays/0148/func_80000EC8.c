// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_FlameMove(EnHonotrap* this, PlayState* play) {
    Actor* thisx = &this->actor;
    Vec3f speed;
    s32 cond;

    Math_StepToF(&this->speedMod, 13.0f, 0.5f);
    speed.x = fabsf(this->speedMod * thisx->velocity.x);
    speed.y = fabsf(this->speedMod * thisx->velocity.y);
    speed.z = fabsf(this->speedMod * thisx->velocity.z);
    cond = true;
    cond &= Math_StepToF(&thisx->world.pos.x, this->targetPos.x, speed.x);
    cond &= Math_StepToF(&thisx->world.pos.y, this->targetPos.y, speed.y);
    cond &= Math_StepToF(&thisx->world.pos.z, this->targetPos.z, speed.z);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 0.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                UPDBGCHECKINFO_FLAG_10);

    if (this->collider.tris.base.atFlags & AT_BOUNCED) {
        Player* player = GET_PLAYER(play);
        Vec3f shieldNorm;
        Vec3f tempVel;
        Vec3f shieldVec;

        shieldVec.x = -player->shieldMf.xz;
        shieldVec.y = -player->shieldMf.yz;
        shieldVec.z = -player->shieldMf.zz;
        EnHonotrap_GetNormal(&shieldNorm, &shieldVec);
        tempVel = thisx->velocity;
        Math3D_Vec3fReflect(&tempVel, &shieldNorm, &thisx->velocity);
        thisx->speed = this->speedMod * 0.5f;
        thisx->world.rot.y = Math_Atan2S_XY(thisx->velocity.z, thisx->velocity.x);
        EnHonotrap_SetupFlameVanish(this);
    } else if (this->collider.tris.base.atFlags & AT_HIT) {
        thisx->speed = 0.0f;
        thisx->velocity.y = 0.0f;
        EnHonotrap_SetupFlameVanish(this);
    } else if (this->timer <= 0) {
        EnHonotrap_SetupFlameVanish(this);
    } else {
        EnHonotrap_FlameCollisionCheck(this, play);
        if (cond != 0) {
            EnHonotrap_SetupFlameChase(this);
        }
    }
}
