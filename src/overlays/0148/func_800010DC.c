// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_FlameChase(EnHonotrap* this, PlayState* play) {
    s32 pad;

    Math_ScaledStepToS(&this->actor.world.rot.y, this->actor.yawTowardsPlayer, 0x300);
    Math_StepToF(&this->actor.speed, 3.0f, 0.1f);
    this->actor.gravity = (-this->actor.playerHeightRel < 10.0f) ? 0.08f : -0.08f;
    Actor_UpdateVelocityWithGravity(&this->actor);
    if (this->actor.velocity.y > 1.0f) {
        this->actor.velocity.y = 1.0f;
    }
    this->actor.velocity.y *= 0.95f;
    Actor_UpdatePos(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 10.0f, 0.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                UPDBGCHECKINFO_FLAG_10);

    if (this->collider.tris.base.atFlags & AT_BOUNCED) {
        Player* player = GET_PLAYER(play);
        Vec3s shieldRot;

        Matrix_MtxFToYXZRot(&player->shieldMf, &shieldRot, 0);
        this->actor.world.rot.y = ((shieldRot.y * 2) - this->actor.world.rot.y) + 0x8000;
        EnHonotrap_SetupFlameVanish(this);
    } else if (this->collider.tris.base.atFlags & AT_HIT) {
        this->actor.speed *= 0.1f;
        this->actor.velocity.y *= 0.1f;
        EnHonotrap_SetupFlameVanish(this);
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WALL) || (this->timer <= 0)) {
        EnHonotrap_SetupFlameVanish(this);
    } else {
        EnHonotrap_FlameCollisionCheck(this, play);
    }
}
