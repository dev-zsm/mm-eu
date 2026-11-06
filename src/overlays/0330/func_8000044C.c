// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_FlyIdle(EnBat* this, PlayState* play) {
    s32 finishedRotStep;

    EnBat_StepAnimation(this, 1);

    finishedRotStep = Math_ScaledStepToS(&this->actor.shape.rot.y, this->yawTarget, 0x300);

    if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_WALL;
        this->yawTarget = this->actor.wallYaw;
    } else if (Math3D_Dist2DSq(this->actor.world.pos.x, this->actor.world.pos.z, this->actor.home.pos.x,
                               this->actor.home.pos.z) > SQ(300.0f)) {
        this->yawTarget = Actor_WorldYawTowardPoint(&this->actor, &this->actor.home.pos);
    } else if (finishedRotStep && (Rand_ZeroOne() < 0.015f)) {
        this->yawTarget =
            this->actor.shape.rot.y + (((s32)(0x1000 * Rand_ZeroOne()) + 0x1000) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1));
    }

    finishedRotStep = Math_ScaledStepToS(&this->actor.shape.rot.x, this->pitchTarget, 0x100);

    if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (this->actor.depthInWater > -40.0f)) {
        this->pitchTarget = -0x1000;
    } else if (this->actor.world.pos.y < (this->actor.home.pos.y - 100.0f)) {
        this->pitchTarget = -((s32)(0x800 * Rand_ZeroOne()) + 0x800);
    } else if ((this->actor.home.pos.y + 100.0f) < this->actor.world.pos.y) {
        this->pitchTarget = (s32)(0x800 * Rand_ZeroOne()) + 0x800;
    } else if ((finishedRotStep) && (Rand_ZeroOne() < 0.015f)) {
        this->pitchTarget += (s16)(((s32)(0x400 * Rand_ZeroOne()) + 0x400) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1));
        this->pitchTarget = CLAMP(this->pitchTarget, -0x1000, 0x1000);
    }

    if (this->timer != 0) {
        this->timer--;
    }
    if ((this->actor.xzDistToPlayer < 300.0f) && (this->timer == 0) && (Player_GetMask(play) != PLAYER_MASK_STONE) &&
        (sNumberAttacking < BAD_BAT_MAX_NUMBER_ATTACKING) &&
        (!(this->paramFlags & BAD_BAT_PARAMFLAG_CHECK_HEIGHTREL) || (fabsf(this->actor.playerHeightRel) < 150.0f))) {
        EnBat_SetupDiveAttack(this);
    }
}
